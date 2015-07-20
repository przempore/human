//
// Created by przemo on 15.07.15.
//

#include "Sprite.h"

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

