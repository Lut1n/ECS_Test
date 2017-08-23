#ifndef GAME_COMPONENT_DESTROYABLE_H
#define GAME_COMPONENT_DESTROYABLE_H

#include <Engine/Component.h>

class DestroyableComponent : public Component
{
    public:
    
    DestroyableComponent();
    
    virtual ~DestroyableComponent();
	
	virtual Type getType() const;
    
    bool _hasToBeDestroyed;
};

#endif