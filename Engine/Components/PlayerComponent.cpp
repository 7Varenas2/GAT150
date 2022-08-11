#include "PlayerComponent.h"
#include "../Engine.h"
#include <iostream>

namespace neum
{
void PlayerComponent::Update()
{
	std::cout << "Player\n";

	// Update transform with input
	Vector2 direction = Vector2::zero;

	if (g_inputSystem.GetButtonState(key_space) == InputSystem::State::Pressed)
	{
		auto component = m_owner->GetComponent<AudioComponent>();
		if (component)
		{
			component->Play();
		}

	}

	if (g_inputSystem.GetButtonState(key_left) == InputSystem::State::Held)
	{
		m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
	}	
	if (g_inputSystem.GetButtonState(key_right) == InputSystem::State::Held)
	{
		m_owner->m_transform.rotation += 180 * g_time.deltaTime;
	}
	float thrust = 0;
	if (g_inputSystem.GetButtonState(key_up) == InputSystem::State::Held)
	{
		thrust = 500;
	}
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component)
	{
		// Thrust force
		Vector2 force = Vector2::Rotate({ 1,0 }, math::DegToRad(m_owner->m_transform.rotation) * thrust);
		component->ApplyForce(force);

		// Gravitational force
		force = (Vector2{ 400, 300 } - m_owner->m_transform.position).Normalized() * 60.0f;
		component->ApplyForce(force);

	}

}

}
