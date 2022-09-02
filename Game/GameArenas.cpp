#include "GameArenas.h"
#include "Engine.h"
#include "GameComponent/EnemyComponent.h"

namespace neum
{
	void GameArenas::Initialize()
	{
		REGISTER_CLASS(EnemyComponent);

		m_scene = std::make_unique<neum::Scene>();

		rapidjson::Document document;
		std::vector<std::string> sceneNames = { "Scenes/level.txt", "Scenes/tilemap.txt", "Scenes/prefabs.txt" };

		for (auto sceneName : sceneNames)
		{
			bool success = neum::json::Load(sceneName, document);

			if (!success)
			{
				LOG("Could Not Load Scene %s", sceneName.c_str());
				continue;
			}

			m_scene->Read(document);
		}

		m_scene->Initialize();

		m_gameState = gameState::Title_Screen;

		std::cout << "HINT: Press ENTER to Start \n";

		neum::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&GameArenas::OnNotify, this, std::placeholders::_1));
	}

	void GameArenas::Shutdown()
	{
		m_scene->RemoveAll();
	}

	void GameArenas::Update()
	{
		switch (m_gameState)
		{
		case gameState::Title_Screen:

			if (g_inputSystem.GetKeyDown(neum::key_enter) == neum::InputSystem::Pressed)
			{
				m_scene->GetActorFromName("Title")->SetActive(false);
				m_scene->GetActorFromName("Score")->SetActive(true);
				m_gameState = gameState::Level_Start;
			}
			break;

		case gameState::Level_Start:
			for (int i = 0; i < 10; i++)
			{
				auto actor = neum::Factory::Instance().Create<Actor>("Coin");
				actor->m_transform.position = { rands::randomf(0,800),100.0f };
				actor->Initialize();

				m_scene->Add(std::move(actor));
			}
			for (int i = 0; i < 3; i++)
			{
				auto actor = neum::Factory::Instance().Create<Actor>("Ghost");
				actor->m_transform.position = { rands::randomf(0,800),100.0f };
				actor->Initialize();

				m_scene->Add(std::move(actor));
			}
			m_gameState = gameState::Game;
			break;

		case gameState::Game:
		{
			auto actor = m_scene->GetActorFromName("Score");
			auto component = actor->GetComponent<neum::TextComponent>();
			component->SetText(std::to_string(m_score));
		}
		g_inputSystem.Update();
		break;
		case gameState::Player_Dead:
			m_stateTimer -= neum::g_time.deltaTime;
			if (m_stateTimer = 0)
			{
				m_gameState = (m_lives > 0) ? gameState::Level_Start : gameState::Game_Over;
			}
			break;

		case gameState::Game_Over:
			//GameOver Title Active
			break;
		}

		m_scene->Update();
	}

	void GameArenas::Draw(neum::Renderer& renderer)
	{
		m_scene->Draw(renderer);
	}

	void GameArenas::OnNotify(const neum::Event& event)
	{
		if (event.name == "EVENT_ADD_POINTS")
		{
			std::cout << event.name << std::endl;
			std::cout << std::get<int>(event.data) << std::endl;
			m_score += std::get<int>(event.data);
		}
		if (event.name == "EVENT_PLAYER_DEAD")
		{
			m_gameState = gameState::Player_Dead;
			m_stateTimer = 3;
		}
	}
}

