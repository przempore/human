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

        void Game::OnUpdate(float dt)
        {
        }

        void Game::OnDraw(Gem::Graphics& graphics)
        {
        }

        void Game::OnEvent(Gem::Event event)
        {

        }

        void Game::OnInput(Gem::Input input)
        {
            try
            {
                Gem::KeyboardInput kinput = boost::get<Gem::KeyboardInput>(input);

                std::cerr << "OnInput: " << (kinput.m_state == Gem::KeyState::Down ? "down" : "up");
                std::cerr << ", code: ";
                if (kinput.m_state == Gem::KeyState::Down)
                {
                    std::cerr << kinput.m_code << std::endl;
                }
                else
                {
                    std::cerr << kinput.m_code << std::endl;
                }
            }
            catch (boost::bad_get bg)
            {
                std::cerr << "Exception was thrown: boost::bad_get" << std::endl;
            }

        }

        ApplicationPtr CreateApplication()
        {
            return ApplicationPtr(new Game);
        }
    }
}
