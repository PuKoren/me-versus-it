#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <time.h> 
#include "config.h"
#include "IGameObject.h"
#include "Game.h"

class Application{
private:
	float ftime;
	bool m_running;
	Uint32 m_oldtime, m_curtime;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	std::vector<IGameObject*> m_gameobjects;

public:
	Application();
	~Application();
	void pollEvents();
	bool init();
	bool update();
	void draw();
};

#endif