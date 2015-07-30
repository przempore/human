// // Created by przemo on 13.07.15.
//

#include <SDL_image.h>
#include "MainWindow.h"

MainWindow::MainWindow()
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
        grass.reset( new Sprite( "image/grass.jpg", renderer, 0, 0, windowWidth, windowHeight ));
        bob.reset( new Actor( "image/tom.png", renderer, 0, 0, 100, 120 ));//353, 481 ));
    }
}

MainWindow::~MainWindow()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_Quit();
}

void MainWindow::Loop()
{
    while ( running && ( event->type != SDL_QUIT ))
    {
        SDL_PollEvent( event );
        SDL_RenderClear( renderer );

        grass->RenderCopy();
        bob->RenderCopy();

        bob->PlayAnimation(0, 3, 0, 200);

        SDL_RenderPresent( renderer );
    }
}

