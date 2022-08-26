#pragma once
#include "Framework/Component.h"

namespace neum
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		CLASS_DECLARATION(PlayerComponent)

		void Update() override;
		virtual void Initialize() override;
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		float speed = 0;

	};
}