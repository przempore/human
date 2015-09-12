#include "SDL_Setup.hpp"
#include "Defines.hpp"

namespace Components
{
    namespace Core
    {
        SDL_Setup::SDL_Setup()
        {
            if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            {
                printf( "SDL2 could not initialize! SDL2_Error: %s\n", SDL_GetError());
                return;
            }
            else
            {
                if (( window = SDL_CreateWindow(
                        windowTitle,
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        windowWidth,
                        windowHeight,
                        SDL_WINDOW_SHOWN )) == nullptr )
                {
                    printf( "Cannot create window\n" );
                    return;
                }

                if (( renderer = SDL_CreateRenderer( window,
                                                     -1,
                                                     SDL_RENDERER_ACCELERATED )) == nullptr )
                {
                    return;
                }

                event = new SDL_Event();
            }
        }

        SDL_Setup::~SDL_Setup()
        {
            SDL_DestroyWindow( window );
            window = nullptr;

            SDL_DestroyRenderer( renderer );
            renderer = nullptr;

            SDL_Quit();
        }
    }
}