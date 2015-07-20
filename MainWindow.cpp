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
                m_windowTitle,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                m_windowWidth,
                m_windowHeight,
                SDL_WINDOW_SHOWN );
        if ( !window )
        {
            printf( "Cannot create window\n" );
            return;
        }

        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
        event = new SDL_Event();
        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = m_windowWidth;
        rect.h = m_windowHeight;
        grass.reset( new Sprite( "image/grass.jpg", renderer, rect ));
        rect.x = 50;
        rect.y = 50;
        rect.w = 50;
        rect.h = 50;
        bob.reset( new Actor( "image/bob.png", renderer, rect ));
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
    while ( m_running && ( event->type != SDL_QUIT ))
    {
        SDL_PollEvent( event );
        SDL_RenderClear( renderer );

        grass->RenderCopy();
        bob->RenderCopy();
        SDL_RenderPresent( renderer );
    }
}

