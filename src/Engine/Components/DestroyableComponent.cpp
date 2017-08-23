#include <Engine/Components/DestroyableComponent.h>

DestroyableComponent::DestroyableComponent()
	: _hasToBeDestroyed(false)
{
}

DestroyableComponent::~DestroyableComponent()
{
}

Component::Type DestroyableComponent::getType() const {return Type_Position;}