#include "Game.h"

Game::Game(){
	m_fontColor = { 255, 255, 255, 255 };
}

Game::~Game(){
	SDL_FreeSurface(m_mainDrawSurface);
	TTF_CloseFont(m_mainFont);
}

void Game::init(){
	m_mainFont = TTF_OpenFont("resources/fonts/lato/regular.ttf", 32);
	if (m_mainFont != nullptr){
		m_mainDrawSurface = TTF_RenderText_Blended(m_mainFont, "TEST", m_fontColor);
	}
	else{
		std::cout << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
	}
}

void Game::event(SDL_Event& e){

}

void Game::update(float delta){

}

void Game::draw(SDL_Renderer& renderer){

}