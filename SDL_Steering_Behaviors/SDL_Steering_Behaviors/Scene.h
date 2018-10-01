#pragma once

#include <iostream>

class Scene
{
public:
	Scene();
	~Scene();



	virtual void eventHandler();
	virtual void update();
	virtual void draw();

};
