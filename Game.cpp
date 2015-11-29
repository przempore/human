//
// Created by przemo on 01.09.15.
//

#include <iostream>
#include "Game.h"

namespace Game
{
    namespace Core
    {
        void Game::OnStartup()
        {
        }

        void Game::OnShutdown()
        {
        }

        void Game::OnUpdate( float dt )
        {
        }

        void Game::OnDraw( SDL_Renderer *renderer )
        {
        }

        void Game::OnEvent( SDL_Event type, void *event )
        {

        }

        void Game::OnInput( InputType type, void *input )
        {
        }

        ApplicationPtr CreateApplication()
        {
            return ApplicationPtr( new Game );
        }
    }
}
