#include <Engine/Systems/GraphicSystem.h>

#include <iostream>

#include <Engine/Entity.h>
#include <Engine/Components/RenderComponent.h>
#include <Engine/Components/PositionComponent.h>

GraphicSystem::GraphicSystem(sf::RenderTarget* target)
	: _target(target)
{
}

void GraphicSystem::process(std::vector<Entity*>& entities, double globalTime)
{
	renderComponents.clear();
	
	// pull all needed component
	for(unsigned int i=0; i<entities.size(); ++i)
	{
		entities[i]->pullComponent(renderComponents);
	}
	
	// for each one
	for(unsigned int i=0; i<renderComponents.size(); ++i)
	{   
		if(false == renderComponents[i]->_initialized)
		{
			renderComponents[i]->initialized();
		}
		
		positionComponents.clear();
		renderComponents[i]->_entity->pullComponent(positionComponents);
		
		sf::Vector2f position(positionComponents[0]->_position.x*PIX_PER_METER,-positionComponents[0]->_position.y*PIX_PER_METER);
		float orientation = -positionComponents[0]->_orientation * 180.0 / 3.141592;
		
		if(renderComponents[i]->_drawableType == RenderComponent::DrawableType_Rect)
		{
			renderComponents[i]->_graphicShape.setPosition(position);
			renderComponents[i]->_graphicShape.setRotation(orientation);
			_target->draw(renderComponents[i]->_graphicShape, renderComponents[i]->_shader);
		}
		else if(renderComponents[i]->_drawableType == RenderComponent::DrawableType_VertBuff)
		{
			_target->draw(renderComponents[i]->_vertexBuff, renderComponents[i]->_shader);
		}
		else
		{
			std::cout << "error : no drawable Type for this RenderComponent " << this << std::endl;
		}
	}
}