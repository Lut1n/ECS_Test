#include <Engine/Systems/PhysicSystem.h>

#include <Engine/Entity.h>
#include <Engine/Components/MotionComponent.h>
#include <Engine/Components/PositionComponent.h>

PhysicSystem::PhysicSystem()
{
	_timeStep = DEFAULT_TIMESTEP;
	_velocityIterations = DEFAULT_VELOCITY_IT;
	_positionIterations = DEFAULT_POSITION_IT;
	
	b2Vec2 gravity(0.0f,-10.0f);
	_physicWorld = new b2World(gravity);
}

void PhysicSystem::process(std::vector<Entity*>& entities, double globalTime)
{
	_physicWorld->Step(_timeStep, _velocityIterations, _positionIterations);
	
	motionComponents.clear();
	
	// pull all needed component
	for(unsigned int i=0; i<entities.size(); ++i)
	{
		entities[i]->pullComponent(motionComponents);
	}
	
	// for each one
	for(unsigned int i=0; i<motionComponents.size(); ++i)
	{   
		positionComponents.clear();
		motionComponents[i]->_entity->pullComponent(positionComponents);
		
		if(false == motionComponents[i]->_initialized)
		{
			motionComponents[i]->initialized(_physicWorld);
		}
		
		b2Vec2 position = motionComponents[i]->_physicBody->GetPosition();
		float32 angle = motionComponents[i]->_physicBody->GetAngle();
		b2Vec2 velocity = motionComponents[i]->_physicBody->GetLinearVelocity();
	
		positionComponents[0]->_position = sf::Vector2f( position.x, position.y );
		positionComponents[0]->_orientation = angle;
		positionComponents[0]->_velocity = sf::Vector2f( velocity.x, velocity.y);
	}
}