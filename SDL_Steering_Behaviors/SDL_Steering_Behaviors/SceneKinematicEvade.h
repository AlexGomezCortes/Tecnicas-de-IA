#pragma once

#include <vector>
#include "../src/Scene.h"
#include "../src/Agent.h"

class SceneKinematicEvade :
	public Scene
{
public:
	SceneKinematicEvade();
	~SceneKinematicEvade();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
	std::vector<Agent*> agents;
	Vector2D target;
};

