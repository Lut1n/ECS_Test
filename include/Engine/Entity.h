#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <vector>

class Component;
class Engine;

class Entity
{
    public:
    
	Entity(unsigned int ID);
	
	virtual ~Entity();
	
	void addComponent(Component* component);
	
	void removeComponent(Component* component);
	
	template<class T>
	void pullComponent(std::vector<T*>& out)
	{
		for(unsigned int i=0; i<_components.size(); ++i)
		{
			T* casted = dynamic_cast<T*>(_components[i]);
			if( casted != nullptr )
			{
				out.push_back(casted);
			}
		}
	}
	
	virtual void update(Engine* engine, double globalTime);
	
    protected:
    
	unsigned int _ID;
    std::vector<Component*> _components;
};

#endif