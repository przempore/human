//
// Created by przemo on 20.07.15.
//

#include "Actor.h"

Actor::Actor( const char *source,
              SDL_Renderer *renderer,
              SDL_Rect &rect ) : Sprite( source,
                                         renderer,
                                         rect )
{
    SDL_QueryTexture( texture, NULL, NULL, &rect.w, &rect.h );
    Actor::crop.x = rect.x;
    Actor::crop.y = rect.y;
    Actor::crop.w = rect.w;
    Actor::crop.h = rect.h;
}

Actor::~Actor()
{ }

void Actor::Move( int x, int y )
{
    Actor::rect.x = x;
    Actor::rect.y = y;
}

void Actor::RenderCopy()
{
    SDL_RenderCopy( renderer, texture, &crop, &rect );
}

void Actor::PlayAnimation( int beginFrame, int endFrame, int row, float deelay )
{
    if (( animDelay + deelay ) > SDL_GetTicks())
    {
        return;
    }

    if ( endFrame <= currentFrame )
    {
        currentFrame = beginFrame;
    }
    else
    {
        ++currentFrame;
    }

//    crop.x = currentFrame * ( rect.w / 4 );
//    crop.y = row * ( rect.h / 4 );
    crop.w = rect.w / 4;
    crop.h = rect.h / 4 + 40;

    animDelay = SDL_GetTicks();
}