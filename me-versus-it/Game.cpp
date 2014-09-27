#include "Game.h"

Game::Game(): m_scoreFont(32, "[Score]"), m_bestScoreFont(16, "[Best score]"){
	this->m_mainFontRatio = 0.1f;
	this->m_growSpeed = 0.7f;
	this->m_maxFontRatio = 1.0f;
	this->m_minFontRatio = 0.1f;
	this->m_changeKeyCooldown = 5.f;
	this->m_curentChangeKeyCooldown = 0.f;
    this->m_curScore = 0;
    this->m_bestScore = 0;
    this->m_curMultiplier = 1;
}

Game::~Game(){
	
}

void Game::init(){
	m_font.init();
	m_font.setPosition(FontPosition::CENTER);

	m_scoreFont.init();
	m_scoreFont.setPosition(FontPosition::TOPRIGHT);

    m_bestScoreFont.init();
    m_bestScoreFont.setPosition(FontPosition::BOTTOMRIGHT);

    this->generateKey();
}

void Game::incrementScore(){
    this->m_curScore += BASE_SCORE * this->m_curMultiplier;

    if(m_curScore > m_bestScore){
        this->m_bestScore = m_curScore;
        this->m_bestScoreFont.setText("Best score: ");
        this->m_bestScoreFont.appendText(this->m_curScore);
    }

    if(this->m_curentChangeKeyCooldown < 1.f){
        this->m_curMultiplier++;
    }
    this->m_curentChangeKeyCooldown = 0;
    this->m_scoreFont.setText(this->m_curScore);
}

void Game::generateKey(){
    m_curScanCode = (SDL_Scancode)((rand()%(SDL_SCANCODE_Z - SDL_SCANCODE_A)) + SDL_SCANCODE_A);
    const char* a = SDL_GetKeyName(SDL_GetKeyFromScancode(m_curScanCode));
    m_font.setText(a);
    this->m_mainFontRatio = this->m_minFontRatio;

}

void Game::event(SDL_Event& e){
    if(e.key.keysym.scancode == m_curScanCode){
        this->generateKey();
        this->incrementScore();
    }else{
        this->m_curScore = 0;
        this->m_curMultiplier = 1;
        this->m_scoreFont.setText(this->m_curScore);
    }
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
        this->generateKey();
        this->m_curScore = 0;
        this->m_curMultiplier = 1;
        this->m_scoreFont.setText(this->m_curScore);
        this->m_curentChangeKeyCooldown -= this->m_changeKeyCooldown;
	}
}

void Game::draw(SDL_Renderer& renderer){
	m_scoreFont.draw(renderer);
	m_font.draw(renderer);
    m_bestScoreFont.draw(renderer);
}
