#ifndef GAME_SYSTEM_GRAPHIC_H
#define GAME_SYSTEM_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include <Engine/System.h>

static const double PIX_PER_METER = 30.0;

class Entity;
class RenderComponent;
class PositionComponent;

class GraphicSystem : public System
{
    public:
	
	sf::RenderTarget* _target;
    
    GraphicSystem(sf::RenderTarget* target);
	
	virtual void process(std::vector<Entity*>& entities, double globalTime);

    std::vector<RenderComponent*> renderComponents;
    std::vector<PositionComponent*> positionComponents;
};

#endif