//
// Created by przemo on 01.09.15.
//

#include <iostream>
#include "Game.hpp"
#include "Defines.hpp"

namespace Game
{
    namespace Core
    {
        Game::Game()
        {
            grass.reset( new Components::Graphics::Sprite( "image/grass.jpg", sdlSetup->GetRendere(), 0, 0,
                                                           windowWidth,
                                                           windowHeight ));
            bob.reset( new Actor( "image/tom.png", sdlSetup->GetRendere(), 0, 0, 100, 120 ));

        }

        Game::~Game()
        {
            
        }

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
            return ApplicationPtr( new Game() );
        }
    }
}
