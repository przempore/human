//
// Created by przemo on 31.08.15.
//

#include "Application.hpp"

namespace Game
{
    namespace Core
    {
        Game::Core::Application::Application()
        {}

        Game::Core::Application::~Application()
        {}

        void Game::Core::Application::Quit()
        {
            SDL_Event event;
            event.type = SDL_QUIT;
            SDL_PushEvent( &event );
        }
    }
}
