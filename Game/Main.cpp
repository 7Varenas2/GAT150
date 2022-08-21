#include "Engine.h"
#include <iostream>
#include <Serialization/Json.cpp>

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

	rapidjson::Document document;
	bool success = neum::json::Load("json.txt", document);
	assert(success);

	std::string str;
	neum::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	neum::json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	neum::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	neum::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	neum::json::Get(document, "float", f);
	std::cout << f << std::endl;

	neum::Vector2 v2;
	neum::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	neum::Color color;
	neum::json::Get(document, "color", color);
	std::cout << color << std::endl;

	// Create Systems
	neum::g_renderer.Initialize();
	neum::g_inputSystem.Initialize();
	neum::g_audioSystem.Initialize();
	neum::g_resources.Initialize();

	// Create window
	neum::g_renderer.CreateWindow("Neumont", 800, 600);
	neum::g_renderer.SetClearColor(neum::Color{ 50, 50, 50, 255 });

	// Texture load assets
	//std::shared_ptr<neum::Texture> texture = std::make_shared<neum::Texture>();
	//texture->Create(neum::g_renderer, "Purple_Ship.png");
	
	//std::shared_ptr<neum::Model> model = std::make_shared<neum::Model>();
	//model->Create( "Player.txt"); 

	auto texture = neum::g_resources.Get<neum::Texture>("Purple_Ship.png", &neum::g_renderer);

	// Font
	auto font = neum::g_resources.Get<neum::Font>("Fonts/CHECKBK0.TTF",10);

	//Model
	auto mcomponent = std::make_unique<neum::ModelComponent>();
	mcomponent->m_model = neum::g_resources.Get<neum::Model>("Player.txt");
	
	neum::g_audioSystem.AddAudio("name", "");

	// Create actors
	neum::Scene scene;

	neum::Transform transform{ neum::Vector2{ 400, 300 }, 90, {3,3} };
	std::unique_ptr<neum::Actor> actor = std::make_unique<neum::Actor>(transform);
	std::unique_ptr<neum::PlayerComponent> pcomponent = std::make_unique<neum::PlayerComponent>(); // Player
	actor->AddComponent(std::move(pcomponent));

	// Model
	/*std::unique_ptr<neum::ModelComponent> mcomponent = std::make_unique<neum::ModelComponent>();
	mcomponent->m_model = neum::g_resources.Get<neum::Model>("Player.txt");
	actor->AddComponent(std::move(mcomponent));*/

	// Sprite
	//std::unique_ptr<neum::SpriteComponent> scomponent = std::make_unique<neum::SpriteComponent>(); 
	//scomponent->m_texture = texture;
	//actor->AddComponent(std::move(scomponent));

	// Audio
	std::unique_ptr<neum::AudioComponent> acomponent = std::make_unique<neum::AudioComponent>(); 
	acomponent->m_sound = "";
	actor->AddComponent(std::move(acomponent));

	// Physics
	std::unique_ptr < neum::PhysicsComponent> phcomponent = std::make_unique<neum::PhysicsComponent>(); 
	actor->AddComponent(std::move(phcomponent));

	// Child
	neum::Transform transformC{ neum::Vector2{ 40, 30 }, 90, {1,1} };
	std::unique_ptr<neum::Actor> child = std::make_unique<neum::Actor>(transformC);
	std::unique_ptr<neum::ModelComponent> mcomponentC = std::make_unique<neum::ModelComponent>();
	mcomponentC->m_model = neum::g_resources.Get<neum::Model>("Player.txt");
	child->AddComponent(std::move(mcomponentC));

	scene.Add(std::move(actor));


	float angle = 0;
	bool quit = false;
	while (!quit)
	{
		neum::g_time.Tick();
		neum::g_inputSystem.Update();
		neum::g_audioSystem.Update();
		
		//neum::g_audioSystem.PlayAudio("Theme");
		if (neum::g_inputSystem.GetKeyDown(neum::key_escape) == neum::InputSystem::State::Pressed) quit = true;

		// Update scene
		angle += 360.0f *  neum::g_time.deltaTime;
		
		scene.Update();
		//neum::g_inputSystem.Update();

		// Render
		neum::g_renderer.BeginFrame();
		scene.Draw(neum::g_renderer);
		//neum::g_renderer.Draw(texture, { 400,300 }, angle, { 10, 10 }, { 0.5f, 1.0f });
		neum::g_renderer.EndFrame();
	}

	neum::g_audioSystem.Shutdown();
	neum::g_renderer.Shutdown();

}