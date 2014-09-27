#ifndef _FONT_H
#define _FONT_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "config.h"
#include "IGameObject.h"

namespace FontPosition{
	enum FontPosition{
		FREE,
		CENTER,
		TOPLEFT,
		TOPRIGHT,
		BOTTOMLEFT,
		BOTTOMRIGHT
	};
};

class Font : public IGameObject{
private:
	FontPosition::FontPosition m_position;
	int m_size;
	std::string m_fontName;
	std::string m_text;
	TTF_Font* m_mainFont;
	SDL_Color m_fontColor;
	SDL_Surface* m_mainDrawSurface;
	SDL_Texture* m_mainDrawTexture;
	SDL_Rect m_drawRect;
	float m_ratio;

	std::map<std::string, SDL_Texture*> m_texturesCache;

	void updatePosition();
	void refreshTexture();
public:
	Font();
	Font(int p_size, std::string p_text);
	Font(std::string p_fontName, int p_size, std::string p_text);
	~Font();
	void init();
	void event(SDL_Event&);
	void update(float);
	void draw(SDL_Renderer&);
	void changeRatio(float p_ratiom);
	void setRatio(float p_ratio);
	void setPosition(int x, int y);
	void setSize(int p_size);
    template< typename T >
        void setText(T t);
    template< typename T >
            void appendText(T t);
	void setPosition(FontPosition::FontPosition p_position);
};


template< typename T >
void Font::setText(T t){
   std::stringstream w;
   w << t;
   if (m_text.compare(w.str()) != 0){
       m_text = w.str();
       this->refreshTexture();
       this->setRatio(this->m_ratio);
   }
}

template< typename T >
void Font::appendText(T t){
   std::stringstream w;
   w << m_text << t;
   if (m_text.compare(w.str()) != 0){
       m_text = w.str();
       this->refreshTexture();
       this->setRatio(this->m_ratio);
   }
}

#endif
