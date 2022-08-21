#pragma once
#include "..\Math\Vector2.h"
#include "..\EngResource\Resource.h"
#include <string>

struct SDL_Texture;


namespace neum
{
	class Renderer;

	class Texture : public Resource
	{
	public:
		Texture() = default;
		~Texture();

		bool Create(const std::string filename, ...) override;
		bool Create(Renderer& renderer, const std::string& filename);

		Vector2 GetSize() const;

		friend class Renderer; // Allows access to Renderer's privates
	private:
		SDL_Texture* m_texture = nullptr;
	};
}
