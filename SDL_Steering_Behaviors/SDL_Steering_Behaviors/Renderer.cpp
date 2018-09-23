#include "Renderer.h"

Renderer::Renderer()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	m_window = SDL_CreateWindow("STEERING BEHAVIOURS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ANCHO_PANTALLA, ALTO_PANTALLA, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };


	nextKey = 0;
}

Renderer * Renderer::Instance()
{
	if (renderer == nullptr)
	{
		renderer = new Renderer;
	}

	return renderer;
}


Renderer::~Renderer()
{
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	SDL_Quit();
}

void Renderer::Clear()
{
	SDL_RenderClear(m_renderer);
}

void Renderer::Render()
{
	SDL_RenderPresent(m_renderer);
}

int Renderer::loadIMG(std::string path)
{
	SDL_Texture* tempTex = IMG_LoadTexture(m_renderer, path.c_str());
	m_images[nextKey] = tempTex;

	return nextKey++;
}

void Renderer::renderSprite(int id, const SDL_Rect & rect, std::pair<int, int> spriteCoor)
{
	SDL_Rect local;
	local.x = m_spriteData[id].first*spriteCoor.first;
	local.y = m_spriteData[id].second*spriteCoor.second;
	local.w = m_spriteData[id].first;
	local.h = m_spriteData[id].second;

	SDL_RenderCopy(m_renderer, m_images[id], &local, &rect);
}


Renderer* Renderer::renderer = nullptr;
