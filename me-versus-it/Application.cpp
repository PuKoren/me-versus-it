#include "Application.h"

Application::Application(){
	m_curtime = m_oldtime = 0;
	m_window = nullptr;
	m_renderer = nullptr;
	m_running = true;

	m_gameobjects.push_back(new Game());
}

bool Application::init(){
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Me versus It", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (TTF_Init() != 0){
		std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		return false;
	}

	SDL_RenderSetLogicalSize(m_renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	srand(time(NULL));

	for (std::vector<IGameObject*>::iterator it = m_gameobjects.begin(); it != m_gameobjects.end(); ++it){
		(*it)->init();
	}

	m_curtime = SDL_GetTicks();
	return true;
}

Application::~Application(){
	TTF_Quit();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Application::pollEvents(){
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE){
			m_running = false;
		} else if(event.type == SDL_KEYDOWN){
			for (std::vector<IGameObject*>::iterator it = m_gameobjects.begin(); it != m_gameobjects.end(); ++it){
				(*it)->event(event);
			}
		}
	}
}

bool Application::update(){
	m_oldtime = m_curtime;
	m_curtime = SDL_GetTicks();
	ftime = (m_curtime - m_oldtime) / 1000.0f;

	this->pollEvents();

	for (std::vector<IGameObject*>::iterator it = m_gameobjects.begin() ; it != m_gameobjects.end(); ++it){
		(*it)->update(ftime);
	}

	return m_running;
}

void Application::draw(){
	SDL_RenderClear(m_renderer);

	for (std::vector<IGameObject*>::iterator it = m_gameobjects.begin() ; it != m_gameobjects.end(); ++it){
		(*it)->draw(*m_renderer);
	}

	SDL_RenderPresent(m_renderer);
}
