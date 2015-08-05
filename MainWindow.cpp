// // Created by przemo on 13.07.15.
//

#include <SDL_image.h>
#include "MainWindow.h"
#include "Defines.h"

MainWindow::MainWindow()
{
    sdlSetup.reset( new SDL_Setup());

    grass.reset( new Sprite( "image/grass.jpg", sdlSetup->GetRendere(), 0, 0, windowWidth, windowHeight ));
    bob.reset( new Actor( "image/tom.png", sdlSetup->GetRendere(), 0, 0, 100, 120 ));
}

MainWindow::~MainWindow()
{ }

void MainWindow::Loop()
{
    while ( running && ( sdlSetup->GetEvent()->type != SDL_QUIT ))
    {
        SDL_PollEvent( sdlSetup->GetEvent());
        SDL_RenderClear( sdlSetup->GetRendere());

        grass->RenderCopy();
        bob->RenderCopy();

        bob->PlayAnimation( 0, 3, 0, 200 );

        SDL_RenderPresent( sdlSetup->GetRendere());
    }
}

