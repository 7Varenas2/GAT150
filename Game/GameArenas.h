#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

namespace neum
{
	class GameArenas : public neum::Game, public neum::INotify
	{
	public:
		enum class gameState
		{
			Title_Screen,
			Level_Start,
			Game,
			Player_Dead,
			Game_Over
		};

	public:
		// Inherited via Game
		virtual void Initialize() override;
		virtual void Shutdown() override;
		virtual void Update() override;
		virtual void Draw(neum::Renderer& renderer) override;

	private:
		gameState m_gameState = gameState::Title_Screen;
		float m_stateTimer = 0;
		int m_lives = 3;

		// Inherited via INotify
		virtual void OnNotify(const neum::Event& event) override;
	};

}