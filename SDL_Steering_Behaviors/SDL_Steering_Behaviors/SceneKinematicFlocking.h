#pragma once
#include <vector>
#include "../src/Scene.h"
#include "../src/Agent.h"

class SceneKinematicFlocking
	:public Scene
{
public:
	SceneKinematicFlocking();
	~SceneKinematicFlocking();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
	std::vector<Agent*> agents;
	Vector2D target;
};

