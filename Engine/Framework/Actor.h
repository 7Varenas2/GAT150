#pragma once
#include "GameObject.h"
#include "Renderer/Model.h"
#include "Math/Transform.h"
#include "Serialization/Json.h"
#include "Component.h"
#include "Scene.h"
#include "Engine.h"
#include <iostream>
#include <vector>

namespace neum
{
	class Scene; 
	class Renderer;
	
	class Actor : public GameObject, public ISerializable
	{
	public:
		Actor() = default;
		Actor(const Actor& other);
		Actor(const Transform& transform) : m_transform( transform ) {}

		CLASS_DECLARATION(Actor) 

		//std::unique_ptr<GameObject> Clone() override { return std::make_unique<Actor>(*this); }


		void Initialize() override;
		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void OnCollision(Actor* other) {};
		void AddChildren(std::unique_ptr<Actor> child);
		void AddComponent(std::unique_ptr<Component> component);


		float GetRadius() { return 0; }	
		std::string& GetTag() { return m_tag; }
		void SetTag(const std::string& tag) { this->m_tag = m_tag; }

		friend class Scene;
		friend class Component;
		std::string m_tag;

		const std::string& GetName() { return m_name; }
		void SetName(const std::string& m_name) { this->m_name = m_name; }

		void SetDestroy() { m_destroy = true; }

		void SetActive(bool active = true) { active = active;  }
		bool IsActive()  { return active; }

		Transform m_transform;

		template <typename T>
		T* GetComponent();

	protected:
		std::string m_name;
		bool active = true;
		
		bool m_destroy = false;


		Scene* m_scene = nullptr;
		Actor* m_parent = nullptr;

		std::vector<std::unique_ptr<Component>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;
	};

	template<typename T>
	inline T* Actor::GetComponent()
	{

		for (auto& component : m_components)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) { return result; } 
		}
		return nullptr;
	}
}