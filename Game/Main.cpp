#include "Engine.h"
#include "Renderer/Texture.h"
#include "Framework/Factory.h"
#include "document.h"
#include <iostream>
#include <cassert>


// code --> preprocessor --> compiler --> .o --> link --> .exe


int main()
{

	constexpr float degrees = math::RadToDeg(math::Pi);
	std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;

	//Memory
	neu::InitializeMemory();
	neum::SetFilePath("../Assets");

	// Create Systems
	neum::g_renderer.Initialize();
	neum::g_inputSystem.Initialize();
	neum::g_audioSystem.Initialize();
	neum::g_resources.Initialize();
	neum::g_physicsSystem.Initialize();

	// Create window
	neum::g_renderer.CreateWindow("Neumont", 800, 600);
	neum::g_renderer.SetClearColor(neum::Color{ 50, 50, 50, 255 });

	// Create game
	// 	8/26
	//std::unique_ptr<GameArenas> game = std::make_unique<GameArenas>();
	//game->Initialize();


	 //Create actors
	neum::Scene scene;

	// 8/26
	//m_scene = std::make_unique<neum::Scene>();

	rapidjson::Document document;
	bool success = neum::json::Load("level.txt", document);
	assert(success);

	scene.Read(document);
	scene.Initialize();
	//for (auto i = 0; i < 10; i++)
	//{
	//	auto actor = neum::Factory::Instance().Create<neum::Actor>("");
	//	actor->m_transform.position = { rands::randomf(0,800), 100.0f };
	//	actor->Initialize();
	//	scene.Add(std::move(actor));
	//}


	//float angle = 0;
	bool quit = false;
	while (!quit)
	{
		neum::g_time.Tick();
		neum::g_inputSystem.Update();
		neum::g_audioSystem.Update();
		neum::g_physicsSystem.Update();

		
		//neum::g_audioSystem.PlayAudio("Theme");
		if (neum::g_inputSystem.GetKeyDown(neum::key_escape) == neum::InputSystem::State::Pressed) quit = true;

		// Update scene
		//angle += 360.0f *  neum::g_time.deltaTime;
		
		scene.Update();
		//8/26
		//game->Update();
	
		// Render
		neum::g_renderer.BeginFrame();
		scene.Draw(neum::g_renderer);
			
			//8/26
		/*game->Draw(neum::g_renderer);*/
		neum::g_renderer.EndFrame();
	}
	scene.RemoveAll();
	
	//8/26
	//game->Shutdown();
	//game.reset();
	//neum::Factory::Instance().Shutdown();

	neum::g_audioSystem.Shutdown();
	neum::g_renderer.Shutdown();
	neum::g_physicsSystem.Shutdown();


}