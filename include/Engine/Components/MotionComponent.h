#ifndef GAME_COMPONENT_MOTION_H
#define GAME_COMPONENT_MOTION_H

#include <Box2D/Box2D.h>

#include <Engine/Component.h>

class MotionComponent : public Component
{
    public:
	
	enum FixtureType
	{
		FixtureType_Undefined = -1,
		FixtureType_Box = 0,
		FixtureType_Chain
	};
    
    MotionComponent();
    
    virtual ~MotionComponent();
	
	void initialized(b2World* world);
	
	bool _initialized;
	
	virtual Type getType() const ;
    
    b2BodyDef       _physicDef;
    b2Body*         _physicBody;
    b2PolygonShape  _physicBox;
    b2World* _physicWorld;
	b2FixtureDef* _fixtureDef;
	b2ChainShape* _chainDef;
	
	FixtureType _fixtureType;
};

#endif