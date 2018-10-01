#include "Seek.h"

Seek::Seek()
{
	Player_Rect.h = Player_Rect.w= Enemy_Rect.h= Enemy_Rect.w= 30;
	Player_Rect.x = ANCHO_PANTALLA / 2;
	Player_Rect.y = ALTO_PANTALLA / 2;

	Enemy_Rect.x= ANCHO_PANTALLA / 3;
	Enemy_Rect.y = ALTO_PANTALLA / 3;
	
	Renderer::Instance()->loadIMG("../res/Player.png"); //al cargar primero el player le estamos dando el indice 0 dentro del map, por eso en globals.h player index es 0
	Renderer::Instance()->loadIMG("../res/Enemy.png");
	
}

Seek::~Seek()
{
}

void Seek::eventHandler()
{
}

void Seek::update()
{
	//calculos del seek y pasarlos a coordenadas de la imagen del player y del enemigo
}

void Seek::draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->renderIMG(Player_Index, Player_Rect);
	Renderer::Instance()->renderIMG(Enemy_Index, Enemy_Rect);

}
