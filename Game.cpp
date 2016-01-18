//
// Created by przemo on 01.09.15.
//

#include <iostream>
#include "Game.h"
#include "DebugInfo.h"
#include "Input.h"

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

        void Game::OnEvent( Event event )
        {

        }

        void Game::OnInput( Input input )
        {

        }

        ApplicationPtr CreateApplication()
        {
            return ApplicationPtr( new Game );
        }
    }
}
