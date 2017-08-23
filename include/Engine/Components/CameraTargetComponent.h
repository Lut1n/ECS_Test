#ifndef GAME_COMPONENT_CAMERATARGET_H
#define GAME_COMPONENT_CAMERATARGET_H

#include <Engine/Component.h>
#include <Engine/Animation.h>

class CameraTargetComponent : public Component
{
    public:
    
    CameraTargetComponent();
    
    virtual ~CameraTargetComponent();
	
	virtual Type getType() const ;
    
    Animation<float> _animatedZoom;
};

#endif