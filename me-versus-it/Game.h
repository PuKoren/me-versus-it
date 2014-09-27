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
    Font m_bestScoreFont;

    unsigned long long int m_curScore;
    unsigned long long int m_bestScore;
    unsigned int m_curMultiplier;

	float m_mainFontRatio;
	float m_growSpeed;
	float m_maxFontRatio;
	float m_minFontRatio;

	float m_changeKeyCooldown;
	float m_curentChangeKeyCooldown;

    SDL_Scancode m_curScanCode;
public:
	Game();
	~Game();
	void init();
	void event(SDL_Event&);
	void draw(SDL_Renderer&);
	void update(float p_delta);

    void generateKey();
    void incrementScore();
};

#endif
