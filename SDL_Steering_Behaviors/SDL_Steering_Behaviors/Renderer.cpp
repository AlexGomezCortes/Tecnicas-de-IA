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
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	SDL_Texture* tempTex = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	m_images[nextKey] = tempTex;

	return nextKey++;
}

void Renderer::renderIMG(int id, const SDL_Rect & rect)
{
	SDL_RenderCopy(m_renderer, m_images[id], nullptr, &rect);
	SDL_RenderPresent(m_renderer);
}


Renderer* Renderer::renderer = nullptr;
