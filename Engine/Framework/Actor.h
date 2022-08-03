#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"
#include "Scene.h"

namespace neum
{
	class Scene;
	

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : 
			GameObject{ transform }, 
			m_model{ model } {}
		virtual void Update() override {}
		virtual void Draw(neum::Renderer& renderer);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return m_model.GetRadius() * m_transform.scale; }
//		std::string* GetTag() { return m_tag; }

		friend class Scene;

	public:
		std::string m_tag;
	protected:
		bool m_destroy = false;
		Vector2 m_velocity;
		float m_damping;

		Scene* m_scene = nullptr;
		Model m_model;
	};
}