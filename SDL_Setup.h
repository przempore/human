#ifndef SDLTEST_SDL_SETUP_H
#define SDLTEST_SDL_SETUP_H

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class SDL_Setup
{
public:
    SDL_Setup();
    virtual ~SDL_Setup();

public:
    SDL_Event* GetEvent() { return event;}
    SDL_Renderer* GetRendere() { return renderer;}

private:
    SDL_Window *window = nullptr; // the window
    SDL_Event *event = new SDL_Event(); // The event structure
    SDL_Renderer *renderer = nullptr;
};


#endif //SDLTEST_SDL_SETUP_H
