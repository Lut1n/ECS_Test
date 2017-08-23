#include <Engine/Components/RenderComponent.h>



RenderComponent::RenderComponent()
	:_initialized(false)
	, _shader(nullptr)
	, _drawableType(DrawableType_Undefined)
{
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::initialized()
{
	_initialized = true;
}

Component::Type RenderComponent::getType() const {return Type_Graphic;}