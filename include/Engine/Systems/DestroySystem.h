#ifndef GAME_SYSTEM_DESTROY_H
#define GAME_SYSTEM_DESTROY_H

#include <Engine/System.h>

class Entity;
class DestroyableComponent;

class DestroySystem : public System
{
    public:
    
    DestroySystem();
    
    void destroyEntityFrom(std::vector<Entity*>& entities, Entity* target);
	
	virtual void process(std::vector<Entity*>& entities);

    std::vector<DestroyableComponent*> destroyComponents;
};

#endif