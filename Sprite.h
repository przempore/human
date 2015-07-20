//
// Created by przemo on 15.07.15.
//

#ifndef SDLTEST_IMAGEOBJECT_H
#define SDLTEST_IMAGEOBJECT_H

#include <string>
#include <iostream>
#include <SDL_render.h>
#include <SDL_image.h>

class Sprite
{
public:
    Sprite( const char *source, SDL_Renderer *renderer, SDL_Rect rect ) : renderer( renderer ),
                                                                          rect( rect )
    {
        texture = IMG_LoadTexture( renderer, source );
        if ( !texture )
        {
            std::cout << "cannot load texture!\n";
        }
    }

    virtual ~Sprite()
    {
        SDL_DestroyTexture( texture );
    }

public:
    void RenderCopy();

    const SDL_Rect &GetRect() const;

    void SetRect( const SDL_Rect &rect );

protected:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect rect;
};


#endif //SDLTEST_IMAGEOBJECT_H
