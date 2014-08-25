#include "Application.h"

Application::Application(){
	m_curtime = m_oldtime = 0;
	m_window = nullptr;
	m_renderer = nullptr;
}

bool Application::init(){
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Me versus It", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (m_window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr){
		SDL_DestroyWindow(m_window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	m_curtime = SDL_GetTicks();
	return true;
}

Application::~Application(){
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

bool Application::update(){
	m_oldtime = m_curtime;
	m_curtime = SDL_GetTicks();
	ftime = (m_curtime - m_oldtime) / 1000.0f;

	for (std::vector<IGameObject>::iterator it = m_gameobjects.begin() ; it != m_gameobjects.end(); ++it){
		(*it).update(ftime);
	}

	return true;
}

void Application::draw(){
	SDL_RenderClear(m_renderer);

	for (std::vector<IGameObject>::iterator it = m_gameobjects.begin() ; it != m_gameobjects.end(); ++it){
		(*it).draw();
	}

	SDL_RenderPresent(m_renderer);
}