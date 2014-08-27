#ifndef _GAME_H
#define _GAME_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "IGameObject.h"

class Game: public IGameObject{
private:
	TTF_Font* m_mainFont;
	SDL_Color m_fontColor;
	SDL_Surface* m_mainDrawSurface;
	SDL_Texture* m_mainDrawTexture;
public:
	Game();
	~Game();
	void init();
	void event(SDL_Event&);
	void draw(SDL_Renderer&);
	void update(float p_delta);
};

#endif