#pragma once
#include "Renderer.h"
#include "Font.h"
#include <iostream>
#include <string>

struct SDL_Texture;
namespace neum
{
	class Font;
	class Renderer;
	class Color;
	class Vector2;
	
	class Text
	{
	public:
		Text() = default;
		Text(Font* font) : m_font{ font } {}
		~Text();

		 void Create(Renderer& renderer, const std::string& text, const Color& color);
		 void Draw(Renderer& renderer, const Vector2& position);

		
	private:
		Font* m_font; // Nullptr
		SDL_Texture* m_texture; //Nullptr

	};
}