#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include "Globals.h"

class Renderer
{

private:
	SDL_Window * m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	static Renderer *renderer;

	unsigned int nextKey;
	std::map <int, std::pair<int, int>> m_spriteData;
	std::map <int, SDL_Texture*> m_images;

public:
	static Renderer* Instance();

	Renderer();
	~Renderer();

	int loadIMG(std::string path);
	void renderSprite(int id, const SDL_Rect &rect, std::pair<int, int> spriteCoor);

	void Clear();
	void Render();

	SDL_Renderer* getRenderer() { return m_renderer; }
	SDL_Window* getWindow() { return m_window; }



};
