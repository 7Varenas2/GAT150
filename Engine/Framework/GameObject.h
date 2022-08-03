#pragma once
#include "../Math/Transform.h"

namespace neum
{
	class GameObject
	{
	public:
		GameObject() = default;
		GameObject(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() = 0;

				
	protected:
		Transform m_transform;
	};
}