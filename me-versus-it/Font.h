#ifndef _FONT_H
#define _FONT_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "IGameObject.h"

class Font : public IGameObject{
private:
	int m_size;
	std::string m_fontName;
	std::string m_text;
	TTF_Font* m_mainFont;
	SDL_Color m_fontColor;
	SDL_Surface* m_mainDrawSurface;
	SDL_Texture* m_mainDrawTexture;

	void refreshTexture();
public:
	Font();
	Font(std::string p_fontName, int p_size, std::string p_text);
	~Font();
	void init();
	void event(SDL_Event&);
	void update(float);
	void draw(SDL_Renderer&);
	void setSize(int p_size);
	void setText(std::string p_text);
};

#endif