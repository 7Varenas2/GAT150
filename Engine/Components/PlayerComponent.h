#pragma once
#include "../Framework/Component.h"

namespace neum
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		void Update() override;

	};
}