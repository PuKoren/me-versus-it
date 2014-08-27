#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include <SDL.h>

class IGameObject{
public:
    virtual ~IGameObject() = 0;
	virtual void init() = 0;
	virtual void event(SDL_Event&) = 0;
    virtual void draw(SDL_Renderer&) = 0;
	virtual void update(float p_delta) = 0;
};

#endif