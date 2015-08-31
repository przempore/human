// // Created by przemo on 13.07.15.
//

#include <SDL_image.h>
#include "MainWindow.h"
#include "Defines.h"

namespace Game
{
    namespace Core
    {
        MainWindow::MainWindow()
        {
            sdlSetup.reset( new Components::Core::SDL_Setup());

            grass.reset( new Components::Graphics::Sprite( "image/grass.jpg", sdlSetup->GetRendere(), 0, 0,
                                                           windowWidth,
                                                           windowHeight ));
            bob.reset( new Actor( "image/tom.png", sdlSetup->GetRendere(), 0, 0, 100, 120 ));
        }

        MainWindow::~MainWindow()
        { }

        void MainWindow::Loop()
        {
            while ( running && ( sdlSetup->GetEvent()->type != SDL_QUIT ))
            {
                running = !checkIsEscape( sdlSetup->GetEvent());

                SDL_PollEvent( sdlSetup->GetEvent());
                SDL_RenderClear( sdlSetup->GetRendere());

                grass->RenderCopy();
                bob->RenderCopy();

                bob->Move( sdlSetup->GetEvent());

                bob->PlayAnimation( 0, 3, 2, 300 );

                SDL_RenderPresent( sdlSetup->GetRendere());
            }
        }

        bool MainWindow::checkIsEscape( SDL_Event *event )
        {
            return event->type == SDL_KEYDOWN
                   && event->key.keysym.sym == SDLK_ESCAPE;
        }
    }
}
