#pragma once
#include "Renderer.h"
#include "..\Math\Color.h"
#include "..\EngResource\Resource.h"
#include <iostream>
#include <string>

struct _TTF_Font;
namespace neum
{
	/* MAKE IT A RESOURCE*/
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string filename, ...) override;
		void Load(const std::string& filename, int fontSize);

		SDL_Surface* CreateSurface(const std::string& text, const Color& color);
		
		friend class Text;
		_TTF_Font* m_ttfFont = nullptr;
	private:

	};
}
