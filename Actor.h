//
// Created by przemo on 20.07.15.
//

#ifndef SDLTEST_ACTOR_H
#define SDLTEST_ACTOR_H

#include "Sprite.h"

class Actor : public Sprite
{
public:
    Actor( const char *source,
           SDL_Renderer *renderer,
           const SDL_Rect &rect ) : Sprite( source,
                                            renderer,
                                            rect )
    { }

    virtual ~Actor()
    { }

public:
    void Move(int x, int y);
};


#endif //SDLTEST_ACTOR_H
