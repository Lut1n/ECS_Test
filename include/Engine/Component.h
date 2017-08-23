#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

class Entity;

class Component
{
    public:
    
	enum Type
	{
		Type_Undefined = -1,
		Type_Graphic,
		Type_Physic,
		Type_Position,
		Type_EvnHandler,
		Type_Destroyable,
		Type_Updatable,
		Type_Widget,
		
		// type count
		Type_Count
	};
    
    Entity* _entity;
    
    Component();
    
    virtual ~Component();
    
    void compose(Entity* entity);
    void decompose();
	
	virtual Type getType() const ;
	
};

#endif