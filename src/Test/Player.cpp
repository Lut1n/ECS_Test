#include <Test/Player.h>
#include <Engine/Components/PositionComponent.h>
#include <Engine/Components/MotionComponent.h>
#include <Engine/Components/RenderComponent.h>

#include <Engine/Systems/GraphicSystem.h>
#include <Engine/TextureCache.h>

Player::Player(float posx, float posy, float size)
	: Entity(3)
{
	
	PositionComponent* position = new PositionComponent();
	RenderComponent* render = new RenderComponent();
	MotionComponent* physic = new MotionComponent();
	addComponent(position);
	addComponent(render);
	addComponent(physic);
	
	render->_drawableType = RenderComponent::DrawableType_Rect;
	render->_graphicShape.setSize( sf::Vector2f(size*PIX_PER_METER,size*PIX_PER_METER) );
	render->_graphicShape.setTexture(TextureCache::getTexture("bob"));
	render->_graphicShape.setPosition(sf::Vector2f(posx*PIX_PER_METER,-posy*PIX_PER_METER ));
	render->_graphicShape.setOrigin(size*0.5*PIX_PER_METER,size*0.5*PIX_PER_METER);
	
	// physic->_physicDef.fixedRotation = true;
	physic->_physicDef.position.Set(posx,posy);
	physic->_physicDef.type = b2_dynamicBody;
	physic->_physicBox.SetAsBox(size*0.5, size*0.5);
	
	physic->_fixtureType = MotionComponent::FixtureType_Box;
	physic->_fixtureDef = new b2FixtureDef();
	physic->_fixtureDef->shape = &(physic->_physicBox);
	physic->_fixtureDef->density = 1.0f;
	physic->_fixtureDef->friction = 0.3f;
	
	animatedZoom.setValue(1.0, 1.0, 0.0, 0.0);
}

Player::~Player()
{
}


void Player::checkKeyState()
{
	std::vector<MotionComponent*> motions;
	pullComponent(motions);
	
	if(motions.size() > 0 && motions[0]->_physicBody)
	{
		

		b2Vec2 vel = motions[0]->_physicBody->GetLinearVelocity();
		float desiredVel = 0;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			desiredVel = -5.0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			desiredVel = 5.0;
		}
		
		float velChange = desiredVel - vel.x;
		float acc = velChange / (1.0/60.0);
		float force = motions[0]->_physicBody->GetMass() * acc;
		motions[0]->_physicBody->ApplyForce( b2Vec2(force,0), motions[0]->_physicBody->GetWorldCenter(), true );
	}
}


bool Player::onEvent(sf::Event& event)
{
	// jump
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
	{
		
		std::vector<MotionComponent*> motions;
		pullComponent(motions);
		
		if(motions.size() > 0 && motions[0]->_physicBody)
		{
			b2Vec2 vel = motions[0]->_physicBody->GetLinearVelocity();
			float mass = motions[0]->_physicBody->GetMass();
			
			// if(vel.y < 1.0)
			{
			float impulse = mass * 5;
			motions[0]->_physicBody->ApplyLinearImpulse( b2Vec2(0,impulse), motions[0]->_physicBody->GetWorldCenter() , true);
			}
		}
		
		return true;
	}
	
	return false;
}


void Player::update(Engine* engine, double globalTime)
{	
	std::vector<PositionComponent*> positions;
	pullComponent(positions);
	
	checkKeyState();

	sf::View playerView = engine->_app->getView();
	float aspectRatio = playerView.getSize().y / playerView.getSize().x;
	
	sf::Vector2f position(positions[0]->_position.x*PIX_PER_METER,-positions[0]->_position.y*PIX_PER_METER);
	playerView.setCenter(position);
	
	sf::Vector2f vecVel = positions[0]->_velocity;
	
	float vel = sqrt(vecVel.x*vecVel.x + vecVel.y*vecVel.y);
	
	if(vel < 1.0)
		animatedZoom.setValue(1.0, globalTime, 1.0);
	else
		animatedZoom.setValue(2.0, globalTime, 1.0);
	
	playerView.setSize( sf::Vector2f(playerView.getSize().x*animatedZoom.getValue() , playerView.getSize().x*aspectRatio*animatedZoom.getValue()) );
	engine->_app->setView(playerView);
	
	animatedZoom.animate(globalTime);
}