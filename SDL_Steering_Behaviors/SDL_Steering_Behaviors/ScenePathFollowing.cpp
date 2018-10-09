#include "ScenePathFollowing.h"


using namespace std;

ScenePathFollowing::ScenePathFollowing()
{
	Agent *agent = new Agent;
	agent->setPosition(Vector2D(640, 360));
	agent->setTarget(Vector2D(640, 360));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	_path.pathArray.push_back(Vector2D(1000, 800));
	//agent->setTarget(_path.pathArray[agents[0]->currentTargetIndex]);
	agents.push_back(agent);
}

ScenePathFollowing::~ScenePathFollowing()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void ScenePathFollowing::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			_path.pathArray.push_back(Vector2D((float)(event->button.x), (float)(event->button.y)));
		}
		break;
	default:
		break;
	}
	if (_path.pathArray.size() > 0)
	{
		Vector2D steering_force = agents[0]->Behavior()->KinematicSeek(agents[0], _path.pathArray.front(), dtime);
		if (Vector2D::Distance(agents[0]->getPosition(), _path.pathArray.front()) < 30)
		{
			_path.pathArray.pop_front();
			//agents[0]->currentTargetIndex++;
		}
		agents[0]->update(steering_force, dtime, event);
	}
}

void ScenePathFollowing::drawCircle(Vector2D circle)
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)circle.x, (int)circle.y, 15, 255, 0, 0, 255);
}

void ScenePathFollowing::draw()
{
	for each(Vector2D t in _path.pathArray)
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)t.x, (int)t.y, 15, 255, 0, 0, 255);
	}
	agents[0]->draw();
}

const char* ScenePathFollowing::getTitle()
{
	return "SDL Steering Behaviors :: KinematicSeek Demo";
}