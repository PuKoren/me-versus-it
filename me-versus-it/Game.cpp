#include "Game.h"

Game::Game(): m_scoreFont(32, "[score]"){
	this->m_mainFontRatio = 0.1f;
	this->m_growSpeed = 0.7f;
	this->m_maxFontRatio = 1.0f;
	this->m_minFontRatio = 0.1f;
	this->m_changeKeyCooldown = 5.f;
	this->m_curentChangeKeyCooldown = 0.f;
}

Game::~Game(){
	
}

void Game::init(){
	m_font.init();
	
	const char* a = SDL_GetKeyName(SDL_GetKeyFromScancode((SDL_Scancode)(rand()%(SDL_SCANCODE_Z - SDL_SCANCODE_A))));
	m_font.setText(a);

	m_font.setPosition(FontPosition::CENTER);

	m_scoreFont.init();
	m_scoreFont.setPosition(FontPosition::TOPRIGHT);
}

void Game::event(SDL_Event& e){
	//m_font.setText((char)e.key.keysym.sym);
}

void Game::update(float delta){
	this->m_font.setRatio(this->m_mainFontRatio);
	this->m_mainFontRatio += delta * this->m_growSpeed;

	if (this->m_mainFontRatio > this->m_maxFontRatio){
		this->m_growSpeed = -this->m_growSpeed;
		this->m_mainFontRatio = this->m_maxFontRatio;
	}
	else if (this->m_mainFontRatio < this->m_minFontRatio){
		this->m_growSpeed = -this->m_growSpeed;
		this->m_mainFontRatio = this->m_minFontRatio;
	}

	this->m_curentChangeKeyCooldown += delta;
	if(this->m_curentChangeKeyCooldown >= this->m_changeKeyCooldown){
		const char* a = SDL_GetKeyName(SDL_GetKeyFromScancode((SDL_Scancode)(rand()%(SDL_SCANCODE_Z - SDL_SCANCODE_A))));
		m_font.setText(a);
		this->m_curentChangeKeyCooldown -= this->m_changeKeyCooldown;
	}
}

void Game::draw(SDL_Renderer& renderer){
	m_scoreFont.draw(renderer);
	m_font.draw(renderer);
}