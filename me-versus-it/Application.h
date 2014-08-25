#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <SDL.h>
#include <iostream>
#include <vector>
#include "IGameObject.h"

class Application{
private:
	float ftime;
	Uint32 m_oldtime, m_curtime;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	std::vector<IGameObject> m_gameobjects;

public:
	Application();
	~Application();
	bool init();
	bool update();
	void draw();
};

#endif