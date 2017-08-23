#include <Engine/Components/WidgetComponent.h>

WidgetComponent::WidgetComponent()
	: _orientation(0.0)
{
}

WidgetComponent::~WidgetComponent()
{
}

Component::Type WidgetComponent::getType() const {return Type_Widget;}