#pragma once
#include "Agent.h"
#include "Vector2D.h"
#include <vector>

class Agent;

class SteeringBehavior
{
public:
	SteeringBehavior();
	~SteeringBehavior();
	Vector2D KinematicSeek(Agent *agent, Vector2D target, float dtime);
	Vector2D KinematicSeek(Agent *agent, Agent *target, float dtime);
	Vector2D KinematicFlee(Agent *agent, Vector2D target, float dtime);
	Vector2D KinematicFlee(Agent *agent, Agent *target, float dtime);
	Vector2D KinematicPursue(Agent *agent, Vector2D target, float dtime);
	Vector2D KinematicPursue(Agent *agent, Agent *target, float dtime);
	Vector2D KinematicEvade(Agent *agent, Vector2D target, float dtime);
	Vector2D KinematicEvade(Agent *agent, Agent *target, float dtime);
	Vector2D Flocking(std::vector<Agent*> agents, Agent *agent, float dtime);
	Vector2D FlocSeparation(std::vector<Agent*> agents, Agent *agent, float dtime, float neighbor_radius);
	Vector2D FlocCohesion(std::vector<Agent*> agents, Agent *agent, float dtime, float neighbor_radius);
	Vector2D FlocAlignment(std::vector<Agent*>agents, Agent *agent, float dtime, float neighbor_radius);

	/* Add here your own Steering Behavior functions declarations */
	Vector2D Seek(Agent *agent, Vector2D target, float dtime);
	Vector2D Seek(Agent *agent, Agent *target, float dtime);
	Vector2D Flee(Agent *agent, Vector2D target, float dtime);
	Vector2D Flee(Agent *agent, Agent *target, float dtime);
	Vector2D Arrive(Agent *agent, Vector2D target, float dtime);
	Vector2D Arrive(Agent *agent, Agent *target, float dtime);
	//etc...

};
