#include "Engine.h"

namespace neum
{
	InputSystem g_inputSystem;
	Time g_time;
	Renderer g_renderer;
	AudioSystem g_audioSystem;
	ResourceManager g_resources;
	PhysicsSystem g_physicsSystem;

	void Engine::Register()
	{
		Factory::Instance().Register<Actor>("Actor");
	}
}