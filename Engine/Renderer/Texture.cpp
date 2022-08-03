#include "Texture.h"
#include "Renderer.h"

#include<SDL.h>
#include<SDL_image.h>

namespace neum
{
	Texture::~Texture()
	{
		if (m_texture != nullptr)
		{
			SDL_DestroyTexture;
		}

	}

	bool Texture::Create(Renderer& renderer, const std::string& filename)
	{
		// Load Surface
		SDL_Surface* surface = IMG_Load(filename.c_str());

		// Create Texture
		m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
		
		//m_texture = SDL_CreateTexture(renderer.m_renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_TARGET, 209, 209);
		SDL_FreeSurface(surface);

		return true;
	}

	Vector2 Texture::GetSize() const
	{
		SDL_Point point;
		SDL_QueryTexture(m_texture, nullptr, nullptr,&point.x,&point.y);

		return point.x, point.y;

	}

}