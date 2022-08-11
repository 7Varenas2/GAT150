#pragma once
#include "../Framework/Component.h"

namespace neum
{
	class Renderer;
	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;
	};
}