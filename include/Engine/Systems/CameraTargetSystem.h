#ifndef GAME_SYSTEM_CAMERATARGET_H
#define GAME_SYSTEM_CAMERATARGET_H

#include <Engine/System.h>

class Entity;
class PositionComponent;
class CameraTargetComponent;

class CameraTargetSystem : public System
{
    public:
    
    CameraTargetSystem();
	
	virtual void process(std::vector<Entity*>& entities, double globalTime);

    std::vector<PositionComponent*> positionComponents;
    std::vector<CameraTargetComponent*> targetComponents;
};

#endif