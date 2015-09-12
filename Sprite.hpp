//
// Created by przemo on 15.07.15.
//

#ifndef SDLTEST_IMAGEOBJECT_H
#define SDLTEST_IMAGEOBJECT_H

#include <string>
#include <iostream>
#include <SDL_render.h>
#include <SDL_image.h>

namespace Components
{
    namespace Graphics
    {
        class Sprite
        {
        public:
            Sprite( const char *source, SDL_Renderer *renderer, int x, int y, int w, int h );

            virtual ~Sprite();

        public:
            virtual void RenderCopy();

            const SDL_Rect &GetRect() const;

            void SetRect( const SDL_Rect &rect );

        protected:
            SDL_Renderer *renderer;
            SDL_Texture *texture;
            SDL_Rect rect;
        };
    }
}


#endif //SDLTEST_IMAGEOBJECT_H
