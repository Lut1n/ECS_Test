#ifndef DOG_H
#define DOG_H

#include <Engine/Entity.h>

class Dog : public Entity
{
    public:
    
    double lastTime;
    
    Dog(float posx, float posy, float size);
    
	virtual void update(Engine* engine, double globalTime);
};

#endif