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
           SDL_Rect &rect );

    virtual ~Actor();

public:
    void Move(int x, int y);

    void RenderCopy();

    void PlayAnimation( int beginFrame, int endFrame, int row, float deelay );
private:
    int currentFrame = 0;
    int animDelay = 0;
    SDL_Rect crop;
};


#endif //SDLTEST_ACTOR_H
