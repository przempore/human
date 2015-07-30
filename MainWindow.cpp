// // Created by przemo on 13.07.15.
//

#include <SDL_image.h>
#include "MainWindow.h"

MainWindow::MainWindow()
{
    sdlSetup.reset( new SDL_Setup());

    grass.reset( new Sprite( "image/grass.jpg", renderer, 0, 0, windowWidth, windowHeight ));
    bob.reset( new Actor( "image/tom.png", renderer, 0, 0, 100, 120 ));//353, 481 ));
}

MainWindow::~MainWindow()
{
}

void MainWindow::Loop()
{
    while ( running && ( event->type != SDL_QUIT ))
    {
        SDL_PollEvent( event );
        SDL_RenderClear( renderer );

        grass->RenderCopy();
        bob->RenderCopy();

        bob->PlayAnimation( 0, 3, 0, 200 );

        SDL_RenderPresent( renderer );
    }
}

