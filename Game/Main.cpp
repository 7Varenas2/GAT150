#include "Engine.h"
#include "GameArenas.h"
// code --> preprocessor --> compiler --> .o --> link --> .exe


int main()
{

	// Initialize memory
	// neum::InitializeMemory();
	neum::g_renderer.Initialize();
	neum::g_inputSystem.Initialize();
	neum::g_audioSystem.Initialize();
	neum::g_resources.Initialize();
	neum::g_physicsSystem.Initialize();
	neum::g_eventManager.Initialize();

	neum::Engine::Instance().Register();

	neum::SetFilePath("../Assets");

	neum::g_renderer.CreateWindow("Neumont", 800, 600);
	neum::g_renderer.SetClearColor(neum::Color{ 0,0,0,255 });


	// Create Game
	std::unique_ptr<neum::GameArenas> game = std::make_unique<neum::GameArenas>();
	game->Initialize();

	bool quit = false;

	while (!quit)
	{
		// Update (engine)
		neum::g_time.Tick();
		neum::g_inputSystem.Update();
		neum::g_physicsSystem.Update();
		neum::g_audioSystem.Update();

		if (neum::g_inputSystem.GetKeyDown(neum::key_escape)) quit = true;

		game->Update();

		// Render
		neum::g_renderer.BeginFrame();// Begin Frame

		game->Draw(neum::g_renderer);

		neum::g_renderer.EndFrame();// End Frame
	}

	game->Shutdown();
	game.reset();
	neum::Factory::Instance().Shutdown();

	// Shutdown
	neum::g_inputSystem.Shutdown();
	neum::g_physicsSystem.Shutdown();
	neum::g_renderer.Shutdown();
	neum::g_audioSystem.Shutdown();
	neum::g_resources.Shutdown();
	neum::g_renderer.Shutdown();
	neum::g_eventManager.Shutdown();
}