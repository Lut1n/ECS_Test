#ifndef GAME_SYSTEM_PHYSIC_H
#define GAME_SYSTEM_PHYSIC_H

#include <Box2D/Box2D.h>
#include <Engine/System.h>

#define DEFAULT_TIMESTEP 1.0f/60.0f
#define DEFAULT_VELOCITY_IT 8
#define  DEFAULT_POSITION_IT 3

class Entity;
class MotionComponent;
class PositionComponent;

class PhysicSystem : public System
{
    public:
	
	// physic parameters
	float32 _timeStep;
    int32 _velocityIterations;
    int32 _positionIterations;
	b2World* _physicWorld;
    
    PhysicSystem();
	
	virtual void process(std::vector<Entity*>& entities, double globalTime);

    std::vector<MotionComponent*> motionComponents;
    std::vector<PositionComponent*> positionComponents;
};

#endif