#include "Font.h"
#include "Core/Logger.h"
#include <SDL_ttf.h>

namespace neum
{
    Font::Font(const std::string& filename, int fontSize)
    {
        Load(filename, fontSize);
    }

    Font::~Font()
    {
        if (m_ttfFont)
        {
            TTF_CloseFont(m_ttfFont);
            m_ttfFont = nullptr;
        }
    }

    bool Font::Create(const std::string filename, ...)
    {
        //// Check data is not null
        //// va_list - Type to hold information about variable arguments
        //va_list args;

        //// va_start - enables access to variadic function arguments
        //va_start(args, filename);

        //// va_arg - accesses the next variadic function arguments
        //int fontSize = va_arg(args, int);

        ////Note -Opens the File, but has to be classafied as File and not .ttf, Or thats what works i guess
        //m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

        //return true;

        return false;
    }

    bool Font::Load(const std::string& filename, int fontSize)
    {
        m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

        if (m_ttfFont == nullptr)
        {
            LOG("SDL ERROR (Font::Load): %s", SDL_GetError());

        }

        return m_ttfFont;
    }

    SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
    {
        SDL_Color c = *((SDL_Color*)(&color));
        SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, text.c_str(), c);

        if (!surface)
        {
            LOG("SDL ERROR (Font::CreateSurface): %s", SDL_GetError());
        }

        return surface;
    }
}

