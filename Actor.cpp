//
// Created by przemo on 20.07.15.
//

#include "Actor.h"

namespace Game
{
    namespace Core
    {
        Actor::Actor( const char *source,
                      SDL_Renderer *renderer,
                      int x, int y, int w, int h ) : Sprite( source,
                                                             renderer,
                                                             x, y, w, h )
        {
            SDL_QueryTexture( texture, NULL, NULL, &imageWidth, &imageHeigh );
            Actor::crop.x = 0;
            Actor::crop.y = 0;
            Actor::crop.w = w / 4;
            Actor::crop.h = h / 4;
        }

        Actor::~Actor()
        { }

        void Actor::Move( int x, int y )
        {
            Actor::rect.x = x;
            Actor::rect.y = y;
        }

        void Actor::Move( SDL_Event *event )
        {
            switch ( event->type )
            {
                case SDL_KEYDOWN:

                    switch ( event->key.keysym.sym )
                    {
                        case SDLK_a:
                            this->rect.x -= speed;
                            break;
                        case SDLK_s:
                            this->rect.y += speed;
                            break;
                        case SDLK_w:
                            this->rect.y -= speed;
                            break;
                        case SDLK_d:
                            this->rect.x += speed;
                            break;
                        default:
                            break;
                    }

                    break;
                default:
                    break;
            }
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

            crop.x = currentFrame * ( imageWidth / 4 );
            crop.y = row * ( imageHeigh / 4 );
            crop.w = imageWidth / 4;
            crop.h = imageHeigh / 4;

            animDelay = SDL_GetTicks();
        }
    }
}