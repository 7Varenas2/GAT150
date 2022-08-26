#pragma once
#include "Framework/Component.h"
#include "RenderComponent.h"
#include "Math/Rect.h"

namespace neum
{
	class Texture;

	class SpriteAnimComponent : public RenderComponent
	{
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		CLASS_DECLARATION(SpriteAnimComponent)

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float fps = 0.0f;
		int num_columns = 0;
		int num_rows = 0;
		int start_frame = 0;
		int end_frame = 0;

		int frame = 0;
		float frametimer = 0.0f;

		Rect source;
		std::shared_ptr<Texture> m_texture;
	};
}
