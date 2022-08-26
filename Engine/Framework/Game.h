#pragma once
#include <iostream>
#include <memory>

namespace neum
{	
	class Renderer;
	class Scene;

	class Game
	{
	public:
		Game() = default;
		virtual ~Game() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;

		int GetScore() { return m_score; }
		void AddPoints(int points) { m_score += points; }
		//void RemoveLives(int lives) { m_lives -= lives; }

		float AdjustHealth(float health) { return p_health -= health; }
		float GetHealth() { return p_health; }

	protected:
		std::unique_ptr<Scene> m_scene;
		int m_score = 0;
		float p_health = 0;
	};
}