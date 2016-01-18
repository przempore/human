//
// Created by przemo on 31.08.15.
//

#include "Application.h"

namespace Game
{
    namespace Core
    {
        void Game::Core::Application::Quit()
        {
            SDL_Event event;
            event.type = SDL_QUIT;
            SDL_PushEvent( &event );
        }
    }
}
