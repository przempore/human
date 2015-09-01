// // Created by przemo on 13.07.15.
//

#include <SDL_image.h>
#include "MainGame.h"
#include "Defines.h"
#include "Input.h"

namespace Game
{
    namespace Core
    {
        extern ApplicationPtr CreateApplication();

        MainGame::MainGame()
        {
            sdlSetup.reset( new Components::Core::SDL_Setup());

            grass.reset( new Components::Graphics::Sprite( "image/grass.jpg", sdlSetup->GetRendere(), 0, 0,
                                                           windowWidth,
                                                           windowHeight ));
            bob.reset( new Actor( "image/tom.png", sdlSetup->GetRendere(), 0, 0, 100, 120 ));

            application = CreateApplication();
        }

        MainGame::~MainGame()
        { }

        bool MainGame::OnStartUp()
        {
            application->OnStartup();
            return false;
        }

        void MainGame::Loop()
        {
            int time1 = SDL_GetTicks();
            int time2 = 0;
            while ( running )
            {
                running = !CheckIsEscape( sdlSetup->GetEvent());

                CheckSDLEvent( sdlSetup->GetEvent());

                SDL_RenderClear( sdlSetup->GetRendere());

                grass->RenderCopy();
                bob->RenderCopy();

                bob->Move( sdlSetup->GetEvent());

                bob->PlayAnimation( 0, 3, 2, 300 );

                time2 = SDL_GetTicks();

                application->OnUpdate( ( time2 - time1 ) / 1000.f );
                application->OnDraw( sdlSetup->GetRendere() );

                SDL_RenderPresent( sdlSetup->GetRendere());

                time1 = time2;
            }
        }

        bool MainGame::CheckIsEscape( SDL_Event *event )
        {
            return event->type == SDL_KEYDOWN
                   && event->key.keysym.sym == SDLK_ESCAPE;
        }

        void MainGame::CheckSDLEvent( SDL_Event *event )
        {
            while ( SDL_PollEvent( sdlSetup->GetEvent()) != 0 )
            {
                switch ( event->type )
                {
                    case SDL_QUIT:
                    {
                        running = false;
                    }
                        break;

                    case SDL_KEYDOWN:
                    {
                        KeyboardInput input;

                        input.m_state = KeyState::Down;
                        input.m_code = event->key.keysym.sym;

                        application->OnInput( InputType::Keyboard, &input );
                    }
                        break;

                    case SDL_KEYUP:
                    {
                        KeyboardInput input;

                        input.m_state = KeyState::Up;
                        input.m_code = event->key.keysym.sym;

                        application->OnInput( InputType::Keyboard, &input );
                    }
                        break;

                    default:
                    { }
                        break;
                } // switch
            }
        }

        void MainGame::OnShutdown()
        {
            application->OnShutdown();
        }
    }
}
