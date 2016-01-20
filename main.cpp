/*
main.c - Testing SDL2
http://www.squarebitstudios.tk
*/
#include <memory>
#include <SDL_events.h>
#include "SDL_Setup.h"
#include "Input.h"
#include "Sprite.h"
#include "Defines.h"
#include "Game.h"
#include "Actor.h"

namespace Game
{
    namespace Core
    {
        bool CheckIsEscape( SDL_Event *event )
        {
            return event->type == SDL_KEYDOWN
                   && event->key.keysym.sym == SDLK_ESCAPE;
        }

        extern ApplicationPtr CreateApplication();

    }
}
int main( int argc, char *args[] )
{
    Game::Core::ApplicationPtr application{
            Game::Core::CreateApplication()
    };
    Components::Core::SDL_Setup sdlSetup;
    bool running {
            true
    };

	Components::Graphics::Sprite grass( "image/grass.jpg", sdlSetup.GetRendere(), 0, 0,
                                                           windowWidth,
                                                           windowHeight );
    Game::Core::Actor bob( "image/tom.png", sdlSetup.GetRendere(), 0, 0, 100, 120 );

    application->OnStartup();

    Uint32 time1 {
            SDL_GetTicks()
    };
    Uint32 time2 {
           0
    };
    while ( running )
    {
        running = !Game::Core::CheckIsEscape( sdlSetup.GetEvent() );

        while ( SDL_PollEvent( sdlSetup.GetEvent() ) != 0 )
        {
            switch ( sdlSetup.GetEvent()->type )
            {
                case SDL_QUIT:
                {
                    running = false;
                }
                    break;

                case SDL_KEYDOWN:
                {
                    Game::Core::KeyboardInput input;

                    input.m_state = Game::Core::KeyState::Down;
                    input.m_code = sdlSetup.GetEvent()->key.keysym.sym;

                    application->OnInput( Game::Core::Input ( input ) );
                }
                    break;

                case SDL_KEYUP:
                {
                    Game::Core::KeyboardInput input;

                    input.m_state = Game::Core::KeyState::Up;
                    input.m_code = sdlSetup.GetEvent()->key.keysym.sym;

                    application->OnInput( Game::Core::Input( input ) );
                }
                    break;

                default:
                { }
                    break;
            } // switch
        }

        SDL_RenderClear( sdlSetup.GetRendere());

        grass.RenderCopy();
        bob.RenderCopy();

        bob.Move( sdlSetup.GetEvent());

        bob.PlayAnimation( 0, 3, 2, 300 );

        time2 = SDL_GetTicks();

        application->OnUpdate(( time2 - time1 ) / 1000.f );
        application->OnDraw( sdlSetup.GetRendere());

        SDL_RenderPresent( sdlSetup.GetRendere());

        time1 = time2;
    }

    application->OnShutdown();

    return EXIT_SUCCESS;
}
