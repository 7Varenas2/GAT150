#pragma once
#include "../Engine.h"

namespace neum
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;

		CLASS_DECLARATION(PhysicsComponent)

		void Update() override;
		void ApplyForce(Vector2& force) { m_acceleration += force; }


		virtual void Initialize() override;
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		Vector2 m_velocity;
		Vector2 m_acceleration;
		float m_damping = 1;

	};
	
}