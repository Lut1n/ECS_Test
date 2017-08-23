#include <Test/GroundPlatform.h>

#include <Engine/Components/PositionComponent.h>
#include <Engine/Components/MotionComponent.h>
#include <Engine/Components/RenderComponent.h>

#include <Engine/Systems/GraphicSystem.h>
#include <Engine/TextureCache.h>

#include <Engine/Math.h>

#include <iostream>

GroundPlatform::GroundPlatform(float positionX, float positionY, float width)
	: Entity(0)
{
	
	PositionComponent* position = new PositionComponent();
	RenderComponent* render = new RenderComponent();
	MotionComponent* physic = new MotionComponent();
	addComponent(position);
	addComponent(render);
	addComponent(physic);
	
	unsigned int pointCount = 10;
	
	render->_drawableType = RenderComponent::DrawableType_VertBuff;
	render->_vertexBuff.setPrimitiveType(sf::TriangleStrip);
	render->_vertexBuff.resize(pointCount * 2);

	sf::Color color(0, 150, 0);
	
	// This a chain shape with isolated vertices
	std::vector<b2Vec2> vs(pointCount);
	
	// on definit la position des sommets du triangle
	for(unsigned int i=0; i<pointCount*2; i+=2)
	{
		float x = positionX + width*i/pointCount;
		float y1 = positionY;
		float y2 = positionY + ( 1 + 0.5* fractal(x, 1, 4.0) );
		
	   render->_vertexBuff[i] = sf::Vertex( sf::Vector2f(x * PIX_PER_METER, -y2*PIX_PER_METER), color);
	   render->_vertexBuff[i+1] = sf::Vertex( sf::Vector2f(x*PIX_PER_METER, -y1*PIX_PER_METER), color);
	   
		vs[i/2].Set(x, y2);
	}
	
	_shape = new b2ChainShape();
	_shape->CreateChain(vs.data(), vs.size());
	physic->_physicDef.position.Set(0.0,0.0);
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