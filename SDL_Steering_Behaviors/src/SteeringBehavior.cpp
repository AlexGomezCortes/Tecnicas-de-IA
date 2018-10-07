#include "SteeringBehavior.h"



SteeringBehavior::SteeringBehavior()
{
}


SteeringBehavior::~SteeringBehavior()
{
}

Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D DesiredVelocity = Vector2D(target) - Vector2D(agent->getPosition());
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getMaxVelocity();
	Vector2D steering_force = (DesiredVelocity - agent->getVelocity());
	steering_force /= agent->getMaxVelocity();
	steering_force *= agent->max_force;
	return steering_force * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D DesiredVelocity = Vector2D(agent->getPosition() - target);
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getMaxVelocity();
	Vector2D steering_force = (DesiredVelocity - agent->getVelocity());
	steering_force /= agent->getMaxVelocity();
	steering_force *= agent->max_force;
	return steering_force * agent->max_velocity;
}

Vector2D SteeringBehavior::Arrive(Agent * agent, Vector2D target, float dtime)
{
	float radius = 200.f;
	Vector2D DesiredVelocity = Vector2D(target) - Vector2D(agent->getPosition());
	DesiredVelocity.Normalize();

	if (Vector2D::Distance(Vector2D(target), Vector2D(agent->getPosition()))>radius)
	{
		DesiredVelocity *= agent->getMaxVelocity();
	}
	else
	{
		float factor = Vector2D::Distance(Vector2D(target), Vector2D(agent->getPosition()))/radius;
		DesiredVelocity *= agent->getMaxVelocity()*factor;
	}

	
	Vector2D steering_force = (DesiredVelocity - agent->getVelocity());
	steering_force /= agent->getMaxVelocity();
	steering_force *= agent->max_force;
	return steering_force * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicPursue(Agent * agent, Agent * target, float dtime)
{

	if (target->velocity.Length() != 0)
	{
		float T = ((target->position - agent->position) / target->velocity.Length()).Length();
		Vector2D PredictedTarget = target->position + target->velocity * T;
		return  KinematicSeek(agent, PredictedTarget, dtime);
	}
	else
	{
		return KinematicSeek(agent, target, dtime);
	}
}

Vector2D SteeringBehavior::KinematicEvade(Agent *agent, Agent *target, float dtime) {

	if (target->velocity.Length() != 0)
	{
		float T = ((agent->position - target->position) / target->velocity.Length()).Length();
		Vector2D PredictedTarget = target->position + target->velocity * T;
		return  KinematicFlee(agent, PredictedTarget, dtime);
	}
	else
	{
		return KinematicFlee(agent, target, dtime);
	}
}

/* Add here your own Steering Behavior functions definitions */

Vector2D SteeringBehavior::Seek(Agent *agent, Vector2D target, float dtime)
{
	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Seek(Agent *agent, Agent *target, float dtime)
{
	return Seek(agent, target->position, dtime);
}

Vector2D SteeringBehavior::Flee(Agent *agent, Vector2D target, float dtime)
{
	return Vector2D(0,0);
}

Vector2D SteeringBehavior::Flee(Agent *agent, Agent *target, float dtime)
{
	return Flee(agent, target->position, dtime);
}


