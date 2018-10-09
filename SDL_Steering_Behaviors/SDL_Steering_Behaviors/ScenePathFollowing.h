#pragma once
#include <vector>
#include <deque>
#include "../src/Scene.h"
#include "../src/Agent.h"

class ScenePathFollowing :
	public Scene
{
public:
	ScenePathFollowing();
	~ScenePathFollowing();
	void update(float dtime, SDL_Event *event);
	void drawCircle(Vector2D circle);
	void draw();
	const char* getTitle();
	std::vector<Vector2D> targets;
	struct Path
	{
		std::deque<Vector2D> pathArray;
	};
	Path _path;
private:
	std::vector<Agent*> agents;
	int i;
	int j;

};

