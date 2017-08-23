#ifndef GAME_COMPONENT_POSITION_H
#define GAME_COMPONENT_POSITION_H

#include <Engine/Component.h>
#include <SFML/Graphics.hpp>

class PositionComponent : public Component
{
    public:
    
    PositionComponent();
    
    virtual ~PositionComponent();
	
	virtual Type getType() const ;
    
    sf::Vector2f    _position;
    float           _orientation;
    sf::Vector2f    _velocity;
};

#endif