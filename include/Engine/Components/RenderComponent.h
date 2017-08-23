#ifndef GAME_COMPONENT_RENDER_H
#define GAME_COMPONENT_RENDER_H

#include <Engine/Component.h>
#include <SFML/Graphics.hpp>

class RenderComponent : public Component
{
    public:
	
	enum DrawableType
	{
		DrawableType_Undefined = -1,
		DrawableType_Rect = 0,
		DrawableType_VertBuff
	};
    
    RenderComponent();
    
    virtual ~RenderComponent();
	
	void initialized();
	
	bool _initialized;
	
	virtual Type getType() const;
    
    sf::RectangleShape	_graphicShape;
    sf::VertexArray 		_vertexBuff;
    sf::Shader*          		_shader;
	DrawableType			_drawableType;
};

#endif