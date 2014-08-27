#ifndef _GAME_H
#define _GAME_H
#include "IGameObject.h"

class Game: public IGameObject{
private:

public:
	Game();
	~Game();
	void init();
	void event(SDL_Event&);
	void draw(SDL_Renderer&);
	void update(float p_delta);
};

#endif