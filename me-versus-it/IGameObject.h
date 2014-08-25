#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include <SDL.h>

class IGameObject{
public:
    virtual ~IGameObject() = 0;
    virtual void draw() = 0;
	virtual void update(float p_delta) = 0;
};

#endif