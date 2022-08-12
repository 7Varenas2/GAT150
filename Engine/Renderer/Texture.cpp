#include "Texture.h"
#include "Renderer.h"
#include "../Core/Logger.h"
#include <string>
#include<SDL.h>
#include<SDL_image.h>

namespace neum
{
    Texture::~Texture()
    {
        if (m_texture != NULL)
        {
            SDL_DestroyTexture(m_texture);
        }
    }

    bool Texture::Create(const std::string& filename, void* data)
    {
        // Check datta is not null

        Renderer* renderer = static_cast<Renderer*>(data);
        return Create(*renderer, filename);
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface
        SDL_Surface* surface = IMG_Load(filename.c_str());// !! call IMG_Load with c-string of filename
        if (surface == nullptr)
        {
            LOG(SDL_GetError());
            return false;
        }
        // create texture
        m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
        if (m_texture == nullptr)
        {
            LOG(SDL_GetError());
            return false;
        }
        SDL_FreeSurface(surface);
        return true;

    }

    Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);
 
        return Vector2(point.x, point.y); // !! return Vector2 of point.x, point.y
    }

}