#pragma once
#include "RenderComponent.h"

namespace neum
{
	class Texture;
	class SpriteComponent : public RenderComponent
	{
	public:
		// Inherited via RenderComponent
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	public:
		std::shared_ptr<Texture> m_texture;


	};
}
