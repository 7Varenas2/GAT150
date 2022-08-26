#include "PhysicsComponent.h"
#include "Engine.h"

namespace neum 
{
	void PhysicsComponent::Update()
	{
		m_velocity += m_acceleration * g_time.deltaTime;
		m_owner->m_transform.position += m_velocity * g_time.deltaTime;
		m_velocity *= m_damping;
		
		m_acceleration = Vector2::zero;
	}

	void PhysicsComponent::Initialize()
	{
	}

	bool PhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool PhysicsComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, m_velocity);
		READ_DATA(value, m_acceleration);
		READ_DATA(value, m_damping);

		return true;
	}

}
