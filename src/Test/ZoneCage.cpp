#include <Test/ZoneCage.h>

#include <Engine/Components/PositionComponent.h>
#include <Engine/Components/MotionComponent.h>
#include <Engine/Components/RenderComponent.h>

#include <Engine/Systems/GraphicSystem.h>
#include <Engine/TextureCache.h>

#include <iostream>

ZoneCage::ZoneCage()
	: Entity(1)
{
	PositionComponent* position = new PositionComponent();
	RenderComponent* render = new RenderComponent();
	MotionComponent* physic = new MotionComponent();
	addComponent(position);
	addComponent(render);
	addComponent(physic);
	
	const double posx = 10.0;
	const double posy = 10.0;
	const double size = 20.0;
	
	// This a chain shape with isolated vertices
	std::vector<b2Vec2> vs(5);
	const double halfSize = size * 0.5;
	vs[0].Set(-halfSize, -halfSize);
	vs[1].Set(halfSize, -halfSize);
	vs[2].Set(halfSize, halfSize);
	vs[3].Set(-halfSize, halfSize);
	vs[4].Set(-halfSize, -halfSize);
	
	render->_drawableType = RenderComponent::DrawableType_Rect;
	render->_graphicShape.setFillColor (sf::Color(128.0,128.0,128.0));
	render->_graphicShape.setOutlineColor (sf::Color(0, 150, 0));
	render->_graphicShape.setOutlineThickness (10.0);
	render->_graphicShape.setSize( sf::Vector2f(size*PIX_PER_METER,size*PIX_PER_METER) );
	render->_graphicShape.setPosition(sf::Vector2f(posx*PIX_PER_METER,-posy*PIX_PER_METER));
	render->_graphicShape.setOrigin(size*0.5*PIX_PER_METER,size*0.5*PIX_PER_METER);
	
	_shape = new b2ChainShape();
	_shape->CreateChain(vs.data(), vs.size());
	physic->_physicDef.position.Set(posx,posy);
	physic->_chainDef = _shape;
	physic->_fixtureType = MotionComponent::FixtureType_Chain;
	
	render->_shader = new sf::Shader();
	// load only the fragment shader
	if (!render->_shader->loadFromFile("assets/ground_shader.vert", "assets/ground_shader.frag"))
	{
		std::cout << "shader cannot be loaded" << std::endl;
		delete render->_shader;
		render->_shader = nullptr;
	}
}

ZoneCage::~ZoneCage()
{
	delete _shape;
}