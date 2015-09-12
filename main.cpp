/*
main.c - Testing SDL2
http://www.squarebitstudios.tk
*/
#include <memory>
#include "MainGame.hpp"
#include "Input.hpp"

namespace Game
{
    namespace Core
    {
        extern ApplicationPtr CreateApplication();
    }
}

int main( int argc, char *args[] )
{
    std::unique_ptr<Components::Core::SDL_Setup> sdlSetup( new Components::Core::SDL_Setup());
    Game::Core::ApplicationPtr application( Game::Core::CreateApplication());

    application->OnStartup();

    int time1 = SDL_GetTicks();
    int time2 = 0;

    bool quit = false;

    while( !quit )
    {
        while( SDL_PollEvent( sdlSetup->GetEvent() ) != 0 )
        {
            switch( sdlSetup->GetEvent()->type )
            {
                case SDL_QUIT:
                {
                    quit = true;
                }
                    break;

                case SDL_KEYDOWN:
                {
                    Game::Core::KeyboardInput input;

                    input.m_state = Game::Core::KeyState::Down;
                    input.m_code  = sdlSetup->GetEvent()->key.keysym.sym;

                    application->OnInput( Game::Core::InputType::Keyboard, &input );
                }
                    break;

                case SDL_KEYUP:
                {
                    Game::Core::KeyboardInput input;

                    input.m_state = Game::Core::KeyState::Up;
                    input.m_code  = sdlSetup->GetEvent()->key.keysym.sym;

                    application->OnInput( Game::Core::InputType::Keyboard, &input );
                }
                    break;

                default:
                {}
                    break;
            } // switch
        }

        time2 = SDL_GetTicks();

        application->OnUpdate( ( time2 - time1 ) / 1000.f );
        application->OnDraw( sdlSetup->GetRendere() );

        SDL_RenderPresent( sdlSetup->GetRendere() );

        time1 = time2;
    }

    application->OnShutdown();

    return EXIT_SUCCESS;
}
