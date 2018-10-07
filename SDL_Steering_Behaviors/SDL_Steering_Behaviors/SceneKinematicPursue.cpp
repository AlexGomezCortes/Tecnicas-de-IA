#include "SceneKinematicPursue.h"

using namespace std;

SceneKinematicPursue::SceneKinematicPursue()
{
	Agent *agent = new Agent;
	Agent *second_agent = new Agent;
	agent->setPosition(Vector2D(640, 360));
	agent->setTarget(Vector2D(640, 360));
	second_agent->setPosition(Vector2D(840, 460));
	second_agent->setTarget(Vector2D(640, 360));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	second_agent->loadSpriteTexture("../res/zombie1.png", 8);
	agents.push_back(agent);
	agents.push_back(second_agent);
	target = Vector2D(640, 360);
}

SceneKinematicPursue::~SceneKinematicPursue()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneKinematicPursue::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			agents[0]->setTarget(target);
			agents[1]->setTarget(target);
		}
		break;
	default:
		break;
	}

	Vector2D steering_force = agents[0]->Behavior()->KinematicPursue(agents[0], agents[1], dtime);
	Vector2D target_force = agents[1]->Behavior()->KinematicSeek(agents[1], agents[1]->getTarget(), dtime);
	
	agents[0]->update(steering_force, dtime, event);
	agents[1]->update(target_force, dtime, event);
}

void SceneKinematicPursue::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	agents[0]->draw();
	agents[1]->draw();
}

const char* SceneKinematicPursue::getTitle()
{
	return "SDL Steering Behaviors :: KinematicSeek Demo";
}
