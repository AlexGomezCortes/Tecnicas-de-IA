#pragma once
#include "Scene.h"
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Globals.h"

class Seek : public Scene
{
public:
	Seek();
	~Seek();

private:

	SDL_Rect Player_Rect;
	SDL_Rect Enemy_Rect;

	void eventHandler() override;
	void update() override;
	void draw() override;
};
