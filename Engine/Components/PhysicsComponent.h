#pragma once
#include "../Engine.h"

namespace neum
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;

		void Update() override;
		void ApplyForce(Vector2& force) { m_acceleration += force; }

		Vector2 m_velocity;
		Vector2 m_acceleration;
		float m_damping = 1;

	};
	
}