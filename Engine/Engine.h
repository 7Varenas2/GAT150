#pragma once
#include "Serialization/Json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Physics/PhysicsSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Texture.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Factory.h"
#include "Framework/Singleton.h"

#include "Components/PlayerComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/ModelComponent.h"
#include "Components/PhysicsComponent.h"

#include "EngResource/ResourceManager.h"

#include <iostream>
#include <vector>
#include <memory>

namespace neum 
{
	// Extern declares
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};

}
