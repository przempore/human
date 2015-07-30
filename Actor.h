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
           int x, int y, int w, int h );

    virtual ~Actor();

public:
    void Move( int x, int y );

    void RenderCopy() override;

    void PlayAnimation( int beginFrame, int endFrame, int row, float deelay );

private:
    int currentFrame = 0;
    int animDelay = 0;
    SDL_Rect crop;
    int imageWidth;
    int imageHeigh;
};


#endif //SDLTEST_ACTOR_H
