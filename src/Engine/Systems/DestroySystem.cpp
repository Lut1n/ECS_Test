#include <Engine/Systems/DestroySystem.h>

#include <Engine/Entity.h>
#include <Engine/Components/DestroyableComponent.h>

DestroySystem::DestroySystem()
{
}

void DestroySystem::destroyEntityFrom(std::vector<Entity*>& entities, Entity* target)
{
	for(unsigned int e=0; e<entities.size(); ++e)
	{
		if(entities[e] == target)
		{
			delete entities[e];
			entities[e] = nullptr;
		}
	}
}

void DestroySystem::process(std::vector<Entity*>& entities)
{
	destroyComponents.clear();
	
	// pull all needed component
	for(unsigned int i=0; i<entities.size(); ++i)
	{
		entities[i]->pullComponent(destroyComponents);
	}
	
	// for each one
	for(unsigned int i=0; i<destroyComponents.size(); ++i)
	{   
		if( destroyComponents[i]->_hasToBeDestroyed )
		{
			destroyEntityFrom(entities, destroyComponents[i]->_entity);
		}
	}
}