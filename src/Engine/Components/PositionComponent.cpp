#include <Engine/Components/PositionComponent.h>


PositionComponent::PositionComponent()
	: _orientation(0.0)
{
}

PositionComponent::~PositionComponent()
{
}

Component::Type PositionComponent::getType() const {return Type_Position;}