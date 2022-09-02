#pragma once 
#include "Math/Vector2.h" 
#include "EngResource/Resource.h" 
#include <string> 

struct SDL_Texture;
struct SDL_Surface;


namespace neum
{
	class Renderer;

	class Texture : public Resource
	{
		friend class Renderer;

	public:
		Texture() = default;
		~Texture();

		bool Create(const std::string name, ...) override;
		bool Create(neum::Renderer& renderer, const std::string& filename);
		bool CreateFromSurface(SDL_Surface* surface, Renderer& renderer);

		Vector2 GetSize() const;

		SDL_Texture* m_texture = nullptr;
	private:
	};
}
