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
		//si clickamos el 1, 
		//escena=new seek()

		//si clickamos el 2
		//escena=new flee()

		//y asi con todos los comportamientos, es bastante más simple que lo del profe



		escena->update();
		escena->draw();

	}

	return 0;
}