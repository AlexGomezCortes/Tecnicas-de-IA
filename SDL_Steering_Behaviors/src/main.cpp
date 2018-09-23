#include <iostream>
#include <SDL.h>
#include "../SDL_Steering_Behaviors/Renderer.h"
#include <SDL_image.h>



using namespace std;
SDL_Event event;

int main(int argc, char ** argv)
{
	bool quit = false;

	Renderer::Instance();
	

	while (!quit)
	{
		/* Keyboard events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_1)
			{
			
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_2)
			{
			}
			if ((event.key.keysym.scancode == SDL_SCANCODE_Q) || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			{
				quit = true;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_F)
			{

			}
			break;
		case SDL_QUIT:
			quit = true;
			break;
		}

	}

	return 0;
}