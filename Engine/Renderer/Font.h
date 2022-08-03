#pragma once
#include "Renderer.h"
#include "..\Math\Color.h"
#include <iostream>
#include <string>

struct _TTF_Font;
namespace neum
{
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontSize);
		_TTF_Font* m_ttfFont = nullptr;
	private:

	};
}
