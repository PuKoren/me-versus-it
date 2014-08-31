#include "Game.h"

Game::Game(): m_scoreFont(32, "[score]"){
	
}

Game::~Game(){
	
}

void Game::init(){
	m_font.init();
	m_font.setText("A");
	m_font.setPosition(FontPosition::CENTER);

	m_scoreFont.init();
	m_scoreFont.setPosition(FontPosition::TOPRIGHT);
}

void Game::event(SDL_Event& e){

}

void Game::update(float delta){
	m_font.update(delta);
	m_scoreFont.update(delta);
}

void Game::draw(SDL_Renderer& renderer){
	m_scoreFont.draw(renderer);
	m_font.draw(renderer);
}