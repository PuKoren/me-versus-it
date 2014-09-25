#include "Font.h"

Font::Font(){
	m_fontName = "resources/fonts/lato/regular.ttf";
	m_size = 512;
	m_text = "";
	m_mainDrawTexture = nullptr;
	m_ratio = 1.0f;
    m_fontColor = { 255, 255, 255, 255 };
	setPosition(0, 0);
}

Font::Font(int p_size, std::string p_text){
	m_fontName = "resources/fonts/lato/regular.ttf";
	m_size = p_size;
	m_text = p_text;
	m_mainDrawTexture = nullptr;
	m_ratio = 1.0f;
    m_fontColor = { 255, 255, 255, 255 };
	setPosition(0, 0);
}

Font::Font(std::string p_fontName, int p_size, std::string p_text){
	m_fontName = p_fontName;
	m_size = p_size;
	m_text = p_text;
	m_mainDrawTexture = nullptr;
	m_ratio = 1.0f;
    m_fontColor = { 255, 255, 255, 255 };
	setPosition(0, 0);
}

Font::~Font(){
	for (std::map<std::string, SDL_Texture*>::iterator it = m_texturesCache.begin() ; it != m_texturesCache.end(); ++it){
		SDL_DestroyTexture(it->second);
	}
	
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
	m_mainDrawTexture = nullptr;
}

void Font::setText(std::string p_text){
	if (m_text.compare(p_text) != 0){
		m_text = p_text;
		this->refreshTexture();
		this->setRatio(this->m_ratio);
	}
}

void Font::setText(char p_text){
	std::stringstream ss;
	std::string str;
	ss << p_text;
	ss >> str;
	this->setText(str);
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
	this->m_drawRect.w = (int)(iW * p_ratio);
	this->m_drawRect.h = (int)(iH * p_ratio);

	this->updatePosition();
}

void Font::setPosition(int x, int y){
	this->m_position = FontPosition::FREE;
	this->m_drawRect.x = x;
	this->m_drawRect.y = y;
	this->updatePosition();
}

void Font::setPosition(FontPosition::FontPosition p_position){
	this->m_position = p_position;
	this->updatePosition();
}

void Font::changeRatio(float p_ratiom){
	this->setRatio(this->m_ratio + p_ratiom);
}

void Font::updatePosition(){
	int iW, iH;
	SDL_QueryTexture(this->m_mainDrawTexture, NULL, NULL, &iW, &iH);
	this->m_drawRect.w = (int)(iW * m_ratio);
	this->m_drawRect.h = (int)(iH * m_ratio);

	if(this->m_position == FontPosition::FREE) return;

	switch(this->m_position){
	case FontPosition::CENTER:
		this->m_drawRect.x = (SCREEN_WIDTH /2) - (this->m_drawRect.w/2);
		this->m_drawRect.y = (SCREEN_HEIGHT /2) - (this->m_drawRect.h/2);
		break;
	case FontPosition::TOPLEFT:
		this->m_drawRect.x = 0;
		this->m_drawRect.y = 0;
		break;
	case FontPosition::TOPRIGHT:
		this->m_drawRect.x = SCREEN_WIDTH - this->m_drawRect.w;
		this->m_drawRect.y = 0;
		break;
	case FontPosition::BOTTOMLEFT:
		this->m_drawRect.x = 0;
		this->m_drawRect.y = SCREEN_HEIGHT - this->m_drawRect.h;
	case FontPosition::BOTTOMRIGHT:
		this->m_drawRect.x = SCREEN_WIDTH - this->m_drawRect.w;
		this->m_drawRect.y = SCREEN_HEIGHT - this->m_drawRect.h;
	}
}

void Font::event(SDL_Event& e){

}

void Font::update(float delta){

}

void Font::draw(SDL_Renderer& renderer){
	if (m_mainDrawTexture == nullptr){
		if(!m_texturesCache.count(m_text)){
			m_texturesCache[m_text] = SDL_CreateTextureFromSurface(&renderer, m_mainDrawSurface);
		}
		m_mainDrawTexture = m_texturesCache[m_text];
		this->setRatio(this->m_ratio);
	}

	SDL_RenderCopy(&renderer, m_mainDrawTexture, NULL, &m_drawRect);
}
