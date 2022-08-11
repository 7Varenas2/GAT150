#pragma once
#include "GameObject.h"
#include "Component.h"
#include "../Renderer/Model.h"
#include "Scene.h"
#include "../Engine.h"
#include <iostream>
#include <vector>

namespace neum
{
	class Scene; 
	class Renderer;
	

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		void AddComponent(std::unique_ptr<Component> component);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; }	
		std::string& GetTag() { return m_tag; }
		friend class Scene;
		friend class Component;
		Transform m_transform;

		std::string m_tag;
		template <typename T>
		T* GetComponent();

	protected:
		bool m_destroy = false;
		Vector2 m_velocity;
		float m_damping;

		Scene* m_scene = nullptr;
		std::vector<std::unique_ptr<Component>> m_components;
	};

	template<typename T>
	inline T* Actor::GetComponent()
	{

		for (auto& component : m_components)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}
		return nullptr;
	}
}