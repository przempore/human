//
// Created by przemo on 15.07.15.
//

#include "Sprite.hpp"

namespace Components
{
    namespace Graphics
    {
        Sprite::Sprite( const char *source, SDL_Renderer *renderer, int x, int y, int w, int h ) : renderer( renderer )
        {
            texture = IMG_LoadTexture( renderer, source );
            if ( !texture )
            {
                std::cout << "cannot load texture " << source << "!\n";
            }

            rect.x = x;
            rect.y = y;
            rect.w = w;
            rect.h = h;
        }

        Sprite::~Sprite()
        {
            SDL_DestroyTexture( texture );
        }

        void Sprite::RenderCopy()
        {
            SDL_RenderCopy( renderer, texture, NULL, &rect );
        }

        const SDL_Rect &Sprite::GetRect() const
        {
            return rect;
        }

        void Sprite::SetRect( const SDL_Rect &rect )
        {
            Sprite::rect = rect;
        }

    }
}
