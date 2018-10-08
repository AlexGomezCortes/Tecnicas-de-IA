#include "SceneKinematicFlocking.h"



SceneKinematicFlocking::SceneKinematicFlocking()
{
	for (int i = 0; i < 60; i++)
	{
		Agent *agent = new Agent;
		int posX = rand() % 1200;
		int posY = rand() % 700;
		agent->setPosition(Vector2D(posX, posY));
		//agent->setTarget(Vector2D(posX, posY));
		agent->loadSpriteTexture("../res/zombie1.png", 8);
		agent->setMass(0.1);
		agents.push_back(agent);
		target = Vector2D(posX, posY);
	}
}


SceneKinematicFlocking::~SceneKinematicFlocking()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneKinematicFlocking::update(float dtime, SDL_Event * event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			for (int i = 0; i < agents.size(); i++)
			{
				agents[i]->setTarget(target);
			}
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < agents.size(); i++)
	{
		Vector2D flock = agents[i]->Behavior()->Flocking(agents, agents[i], dtime);
		Vector2D seek = agents[i]->Behavior()->KinematicSeek(agents[i], agents[i]->getTarget(), dtime);
		Vector2D steering_force = seek + flock;
		agents[i]->update(seek + flock, dtime, event);
	}
}

void SceneKinematicFlocking::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (int i = 0; i < agents.size(); i++)
	{
		agents[i]->draw();
	}
}

const char * SceneKinematicFlocking::getTitle()
{
	return "SDL Steering Behaviors :: KinematicFlocking Demo";
}
