#include <iostream>
#include <SDL.h>
#include "../SDL_Steering_Behaviors/Renderer.h"
#include <SDL_image.h>
#include "../SDL_Steering_Behaviors/Scene.h"
#include "../SDL_Steering_Behaviors/Seek.h"



using namespace std;
SDL_Event event;

int main(int argc, char ** argv)
{
	bool quit = false;
	Scene* escena = new Seek();
	

	while (!quit)
	{
		escena->update();
		escena->draw();

	}

	return 0;
}