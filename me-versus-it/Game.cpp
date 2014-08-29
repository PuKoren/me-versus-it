#include "Game.h"

Game::Game(){
	
}

Game::~Game(){
	
	
}

void Game::init(){
	m_font.init();
	m_font.setText("Test");
}

void Game::event(SDL_Event& e){
	m_font.event(e);
}

void Game::update(float delta){
	m_font.update(delta);
}

void Game::draw(SDL_Renderer& renderer){
	m_font.draw(renderer);
}