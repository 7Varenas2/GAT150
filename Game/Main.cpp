#include "Engine.h"

//#include <Framework/Actor.cpp>
//#include <Framework/Scene.cpp>
//#include <Framework/Scene.cpp>
//#include <Renderer/Model.cpp>
//#include <Renderer/Text.cpp>
//
//#include <iostream>
//#include <vector>
//#include <array>
//#include <list>
//#include <algorithm>


int main()
{
	std::cout << "Hello World\n";

	//Memory
	neu::InitializeMemory();
	neum::SetFilePath("../Assets");

	// Create Systems
	neum::g_renderer.Initialize();
	neum::g_inputSystem.Initialize();
	neum::g_audioSystem.Initialize();

	// Create window
	neum::g_renderer.CreateWindow("Neumont", 800, 600);
	neum::g_renderer.SetClearColor(neum::Color{ 50, 50, 50, 255 });

	// Texture
	std::shared_ptr<neum::Texture> texture = std::make_shared<neum::Texture>();
	texture->Create(neum::g_renderer, "Tiger.png");


	bool quit = false;
	while (!quit)
	{
		neum::g_time.Tick();
		neum::g_inputSystem.Update();
		neum::g_audioSystem.Update();
		neum::g_audioSystem.PlayAudio("Theme");
		if (neum::g_inputSystem.GetKeyDown(neum::key_escape) == neum::InputSystem::State::Pressed) quit = true;

		neum::g_inputSystem.Update();

		// Render
		neum::g_renderer.BeginFrame();

		neum::g_renderer.Draw(texture, { 400,300 }, 0);

		neum::g_renderer.EndFrame();
	}

	neum::g_audioSystem.Shutdown();
	neum::g_renderer.Shutdown();

}