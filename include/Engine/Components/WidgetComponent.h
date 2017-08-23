#ifndef GAME_COMPONENT_WIDGET_H
#define GAME_COMPONENT_WIDGET_H

#include <SFML/Graphics.hpp>

#include <Engine/Component.h>

class WidgetComponent : public Component
{
    public:
    
    WidgetComponent();
    
    virtual ~WidgetComponent();
	
	virtual Type getType() const ;
    
    sf::Vector2f    _position;
    float           _orientation;
    sf::Vector2f    _velocity;
};

#endif