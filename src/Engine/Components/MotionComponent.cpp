#include <Engine/Components/MotionComponent.h>

#include <iostream>

MotionComponent::MotionComponent()
	: _physicBody(nullptr)
	, _physicWorld(nullptr)
	, _initialized(false)
	, _fixtureType(FixtureType_Undefined)
{
}

MotionComponent::~MotionComponent()
{
	if(_physicBody && _physicWorld)
		_physicWorld->DestroyBody(_physicBody);
}

void MotionComponent::initialized(b2World* world)
{
	_physicWorld = world;
	_physicBody = _physicWorld->CreateBody(&_physicDef);
	
	if(_fixtureType == FixtureType_Box)
	{
		_physicBody->CreateFixture(_fixtureDef);
	}
	else if(_fixtureType == FixtureType_Chain)
	{
		_physicBody->CreateFixture(_chainDef, 0);
	}
	else
	{
		std::cout << "error : no fixture Type for this MotionComponent " << this << std::endl;
	}
	
	_initialized = true;
}

Component::Type MotionComponent::getType() const {return Type_Physic;}