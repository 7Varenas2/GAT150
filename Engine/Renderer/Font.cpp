#include "Font.h"
#include "Renderer.h"
#include <SDL_ttf.h>

neum::Font::Font(const std::string& filename, int fontSize)
{
	Load(filename, fontSize);
}

neum::Font::~Font()
{
	if (m_ttfFont)
	{
		TTF_CloseFont(m_ttfFont);
		m_ttfFont = nullptr;
	}
}

void neum::Font::Load(const std::string& filename, int fontSize)
{
	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
}
