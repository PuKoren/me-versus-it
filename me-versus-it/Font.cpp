#include "Font.h"

Font::Font(){
	m_fontName = "resources/fonts/lato/regular.ttf";
	m_size = 32;
	m_text = "";
	m_mainDrawTexture = nullptr;
	m_ratio = 1.0f;
	setPosition(0, 0);
}

Font::Font(std::string p_fontName, int p_size, std::string p_text){
	m_fontName = p_fontName;
	m_size = p_size;
	m_text = p_text;
	m_mainDrawTexture = nullptr;
	m_ratio = 1.0f;
	setPosition(0, 0);
}

Font::~Font(){
	SDL_DestroyTexture(m_mainDrawTexture);
	SDL_FreeSurface(m_mainDrawSurface);
	TTF_CloseFont(m_mainFont);
}

void Font::init(){
	m_mainFont = TTF_OpenFont(m_fontName.c_str(), m_size);
	if (m_mainFont != nullptr){
		m_mainDrawSurface = TTF_RenderText_Blended(m_mainFont, m_text.c_str(), m_fontColor);
	}
	else{
		std::cout << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
	}
}

void Font::refreshTexture(){
	m_mainDrawSurface = TTF_RenderText_Blended(m_mainFont, m_text.c_str(), m_fontColor);
	SDL_DestroyTexture(m_mainDrawTexture);
	m_mainDrawTexture = nullptr;
}

void Font::setText(std::string p_text){
	if (m_text.compare(p_text) != 0){
		m_text = p_text;
		this->refreshTexture();
	}
}

void Font::setSize(int p_size){
	if (p_size != m_size){
		m_size = p_size;
		TTF_CloseFont(m_mainFont);
		m_mainFont = TTF_OpenFont(m_fontName.c_str(), m_size);
	}
	this->refreshTexture();
}

void Font::setRatio(float p_ratio){
	this->m_ratio = p_ratio;
	int iW, iH;
	SDL_QueryTexture(this->m_mainDrawTexture, NULL, NULL, &iW, &iH);
	this->m_drawRect.w = iW * p_ratio;
	this->m_drawRect.h = iH * p_ratio;
}

void Font::setPosition(int x, int y){
	this->m_drawRect.x = x;
	this->m_drawRect.y = y;
}

void Font::event(SDL_Event& e){

}

void Font::update(float delta){

}

void Font::draw(SDL_Renderer& renderer){
	if (m_mainDrawTexture == nullptr){
		m_mainDrawTexture = SDL_CreateTextureFromSurface(&renderer, m_mainDrawSurface);
		this->setRatio(this->m_ratio);
	}

	SDL_RenderCopy(&renderer, m_mainDrawTexture, NULL, &m_drawRect);
}