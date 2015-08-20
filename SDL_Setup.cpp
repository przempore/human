#include "SDL_Setup.h"
#include "Defines.h"

SDL_Setup::SDL_Setup()
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL2 could not initialize! SDL2_Error: %s\n", SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow(
                windowTitle,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                windowWidth,
                windowHeight,
                SDL_WINDOW_SHOWN );

        if ( !window )
        {
            printf( "Cannot create window\n" );
            return;
        }

        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
        event = new SDL_Event();
    }
}

SDL_Setup::~SDL_Setup()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_Quit();
}