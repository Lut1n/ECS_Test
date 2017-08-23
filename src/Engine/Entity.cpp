#include <Engine/Entity.h>
#include <Engine/Component.h>
#include <Engine/Engine.h>
    
Entity::Entity(unsigned int ID)
	: _ID(ID)
{
}

Entity::~Entity()
{
}

void Entity:: addComponent(Component* component)
{
	component->_entity = this;
	_components.push_back(component);
}

void Entity::removeComponent(Component* component)
{
	for(unsigned int i=0; i<_components.size(); ++i)
	{
		if(_components[i] == component)
		{
			_components[i]->_entity = nullptr;
			_components[i] = nullptr;
		}
	}
}

void Entity::update(Engine* engine, double globalTime){}