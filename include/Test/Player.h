#ifndef PLAYER_H
#define PLAYER_H

#include <Engine/Entity.h>
#include <Engine/Engine.h>

#include <Engine/Animation.h>


class Player : public Entity, public EventHandler
{
    public:
    
	Animation<float> animatedZoom;
    
    Player(float posx, float posy, float size);
	virtual ~Player();
    
    virtual void checkKeyState();
    
	
    virtual bool onEvent(sf::Event& event);
	
    virtual void update(Engine* engine, double globalTime);
};

#endif