#pragma once
#include "../Math/Transform.h"

namespace neum
{
	class GameObject
	{
	public:
		GameObject() = default;
		
		virtual void Update() = 0;
	};
}