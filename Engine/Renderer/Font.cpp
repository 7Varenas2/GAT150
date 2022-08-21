#include "Font.h"
#include "Renderer.h"
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
        // Check data is not null
        // va_list - Type to hold information about variable arguments
        va_list args;

        // va_start - enables access to variadic function arguments
        va_start(args, filename);

        // va_arg - accesses the next variadic function arguments
        int fontSize = va_arg(args, int);

        // va_end - ends traversal of the cvariadic function arguments
        va_end(args);

        // Create texture (returns true/false if successful
        return  Create(filename, fontSize);
    }

    void Font::Load(const std::string& filename, int fontSize)
    {
        m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
    }
}

