#include <Engine/Components/CameraTargetComponent.h>

CameraTargetComponent::CameraTargetComponent()
{
}

CameraTargetComponent::~CameraTargetComponent()
{
}

Component::Type CameraTargetComponent::getType() const {return Type_Position;}