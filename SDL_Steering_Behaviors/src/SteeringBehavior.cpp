#include "SteeringBehavior.h"



SteeringBehavior::SteeringBehavior()
{
}


SteeringBehavior::~SteeringBehavior()
{
}

/*Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	return steering * agent->max_velocity;
}*/

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

/*Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = agent->position - target;
	steering.Normalize();
	return steering * agent->max_velocity;
}*/

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

/*Vector2D SteeringBehavior::Arrive(Agent * agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	return steering * agent->max_velocity;
}*/

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

//Vector2D SteeringBehavior::KinematicPursue(Agent * agent, Vector2D target, float dtime)
//{
//	
//	float distanceToTarget = Vector2D::Distance(target, Vector2D(agent->getPosition()));
//	float T = distanceToTarget/agent->max_velocity;
//	Vector2D PredictedTarget = target + agent->velocity * T;
//
//	Vector2D DesiredVelocity = PredictedTarget - Vector2D(agent->getPosition());
//
//	Vector2D steering_force = (DesiredVelocity - agent->getVelocity());
//
//	return steering_force * agent->max_velocity;
//}

Vector2D SteeringBehavior::KinematicPursue(Agent * agent, Agent * target, float dtime)
{

	float distanceToTarget = Vector2D::Distance(target->position, Vector2D(agent->getPosition()));
	std::cout << distanceToTarget + '\n';

	float T = distanceToTarget / agent->getVelocity().Length();

	Vector2D PredictedTarget = target->position + target->velocity * T;

	Vector2D DesiredVelocity = PredictedTarget - Vector2D(agent->getPosition());

	Vector2D steering_force = (DesiredVelocity - agent->getVelocity());

	return steering_force * agent->getMaxVelocity();
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


