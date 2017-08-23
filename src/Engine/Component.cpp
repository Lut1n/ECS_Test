#include <Engine/Component.h>
#include <Engine/Entity.h>

    
Component::Component()
{}

Component::~Component()
{}

void Component::compose(Entity* entity)
{_entity = entity;}

void Component::decompose()
{_entity = nullptr;}

Component::Type Component::getType() const
{return Type_Undefined;}