#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

#include <vector>

class Entity;

class System
{
	public:
    
    System();
    
    virtual ~System();
	
	virtual void process(std::vector<Entity*>& entities, double globalTime);
};

#endif