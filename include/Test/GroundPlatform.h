#ifndef PLATFORM_H
#define PLATFORM_H

#include <Engine/Entity.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class GroundPlatform : public Entity
{
    public:
    
    sf::VertexArray _graphicShape;
	b2ChainShape* _shape;
    
    GroundPlatform(float positionX, float positionY, float width);
};

#endif