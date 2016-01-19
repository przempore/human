/*
main.c - Testing SDL2
http://www.squarebitstudios.tk
*/
#include <memory>
#include "MainGame.h"

bool CheckIsEscape( SDL_Event *event )
{
    return event->type == SDL_KEYDOWN
           && event->key.keysym.sym == SDLK_ESCAPE;
}

void CheckSDLEvent( SDL_Event *event )
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

                application->OnInput( Input( input ) );
            }
                break;

            case SDL_KEYUP:
            {
                KeyboardInput input;

                input.m_state = KeyState::Up;
                input.m_code = event->key.keysym.sym;

                application->OnInput( Input( input ) );
            }
                break;

            default:
            { }
                break;
        } // switch
    }
}

int main( int argc, char *args[] )
{

	ApplicationPtr application = CreateApplication();
	Components::Core::SDL_Setup sdlSetup;

	bool running = true;

	Components::Graphics::Sprite grass( "image/grass.jpg", sdlSetup->GetRendere(), 0, 0,
                                                           windowWidth,
                                                           windowHeight );
	Actor bob( "image/tom.png", sdlSetup->GetRendere(), 0, 0, 100, 120 );

    application->OnStartup();

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

        application->OnUpdate(( time2 - time1 ) / 1000.f );
        application->OnDraw( sdlSetup->GetRendere());

        SDL_RenderPresent( sdlSetup->GetRendere());

        time1 = time2;
    }

    application->OnShutdown();

    return EXIT_SUCCESS;
}
