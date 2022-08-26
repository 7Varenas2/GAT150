#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"

namespace neum
{
	class CollisionComponent : Component, public Collision
	{
	public:
		virtual void Initialize() override;
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value)override;

	

		virtual void Update()override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

	private:

	};
}