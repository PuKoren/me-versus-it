#ifndef _GAME_H
#define _GAME_H
#include <SDL.h>
#include <iostream>
#include "IGameObject.h"
#include "Font.h"

class Game: public IGameObject{
private:
	Font m_font;
	Font m_scoreFont;
	float m_mainFontRatio;
	float m_growSpeed;
	float m_maxFontRatio;
	float m_minFontRatio;
public:
	Game();
	~Game();
	void init();
	void event(SDL_Event&);
	void draw(SDL_Renderer&);
	void update(float p_delta);
};

#endif