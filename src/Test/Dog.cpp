#include <Test/Dog.h>

#include <Engine/Components/PositionComponent.h>
#include <Engine/Components/MotionComponent.h>
#include <Engine/Components/RenderComponent.h>

#include <Engine/Systems/GraphicSystem.h>
#include <Engine/TextureCache.h>

Dog::Dog(float posx, float posy, float size)
	: Entity(0)
{
	
	PositionComponent* position = new PositionComponent();
	RenderComponent* render = new RenderComponent();
	MotionComponent* physic = new MotionComponent();
	addComponent(position);
	addComponent(render);
	addComponent(physic);
	
	render->_drawableType = RenderComponent::DrawableType_Rect;
	render->_graphicShape.setSize( sf::Vector2f(size*PIX_PER_METER,size*PIX_PER_METER) );
	render->_graphicShape.setTexture(TextureCache::getTexture("dog"));
	render->_graphicShape.setPosition(sf::Vector2f(posx*PIX_PER_METER,-posy*PIX_PER_METER));
	render->_graphicShape.setOrigin(size*0.5*PIX_PER_METER,size*0.5*PIX_PER_METER);
	
	physic->_fixtureType = MotionComponent::FixtureType_Box;
	physic->_physicDef.position.Set(posx,posy);
	physic->_physicDef.type = b2_dynamicBody;
	physic->_physicBox.SetAsBox(size*0.5, size*0.5);
	
	physic->_fixtureDef = new b2FixtureDef();
	physic->_fixtureDef->shape = &physic->_physicBox;
	physic->_fixtureDef->density = 1.0f;
	physic->_fixtureDef->friction = 10.0f;
}

void Dog::update(Engine* engine, double globalTime)
{
	std::vector<MotionComponent*> motions;
	pullComponent(motions);
	
	if(motions.size() > 0 && motions[0]->_physicBody)
	{
		if( motions[0]->_physicBody->GetAngle() < -0.2 )
		{
			motions[0]->_physicBody->ApplyTorque( 10.0, true );
		}
		else if( motions[0]->_physicBody->GetAngle() > 0.2 )
		{
			motions[0]->_physicBody->ApplyTorque( -10.0, true );
		}
		
		if(globalTime - lastTime > 0.3)
		{
			b2Vec2 vel = motions[0]->_physicBody->GetLinearVelocity();
			if(vel.y < 1.0)
			//apply gradual force upwards
				motions[0]->_physicBody->ApplyForce( b2Vec2(0,100), motions[0]->_physicBody->GetWorldCenter(), true );
				
			lastTime = globalTime;
		}
	}
}