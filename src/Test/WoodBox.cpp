#include <Test/WoodBox.h>

#include <Engine/Components/PositionComponent.h>
#include <Engine/Components/MotionComponent.h>
#include <Engine/Components/RenderComponent.h>

#include <Engine/Systems/GraphicSystem.h>
#include <Engine/TextureCache.h>
    
WoodBox::WoodBox(float posx, float posy, float size)
	: Entity(0)
{
	
	PositionComponent* position = new PositionComponent();
	RenderComponent* render = new RenderComponent();
	MotionComponent* physic = new MotionComponent();
	addComponent(position);
	addComponent(render);
	addComponent(physic);
	/*
	const double posx = 3.0;
	const double posy = 5.0;
	const double size = 1.0;
	*/
	render->_drawableType = RenderComponent::DrawableType_Rect;
	render->_graphicShape.setSize( sf::Vector2f(size*PIX_PER_METER,size*PIX_PER_METER) );
	render->_graphicShape.setTexture(TextureCache::getTexture("box"));
	render->_graphicShape.setPosition(sf::Vector2f(posx*PIX_PER_METER,-posy*PIX_PER_METER));
	render->_graphicShape.setOrigin(size*0.5*PIX_PER_METER,size*0.5*PIX_PER_METER);
	
	physic->_physicDef.position.Set(posx,posy);
	physic->_physicDef.type = b2_dynamicBody;
	physic->_physicBox.SetAsBox(size*0.5, size*0.5);
	
	physic->_fixtureType = MotionComponent::FixtureType_Box;
	physic->_fixtureDef = new b2FixtureDef();
	physic->_fixtureDef->shape = &physic->_physicBox;
	physic->_fixtureDef->density = 1.0f;
	physic->_fixtureDef->friction = 10.0f;
}