#pragma once
#include "Framework/Component.h"
#include "RenderComponent.h"
#include "Math/Rect.h"

namespace neum
{
	class Texture;
	class SpriteComponent : public RenderComponent
	{
	public:
		// Inherited via RenderComponent
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		CLASS_DECLARATION(SpriteComponent)

		virtual void Initialize() override;
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Rect source;
		std::shared_ptr<Texture> m_texture;


	};
}
