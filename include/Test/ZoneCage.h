#ifndef ZONECAGE_H
#define ZONECAGE_H

#include <Engine/Entity.h>

#include <Box2D/Box2D.h>


class ZoneCage : public Entity
{
    public:
	
	b2ChainShape* _shape;
    
    ZoneCage();
	
	virtual ~ZoneCage();
};

#endif