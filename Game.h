//
// Created by przemo on 01.09.15.
//

#ifndef SDLTEST_GAME_H
#define SDLTEST_GAME_H


#include <memory>
#include <SDL_render.h>
#include <gem/Application.hpp>
//#include "Application.h"

namespace Game
{
    namespace Core
    {
        class Game : public Gem::Application
        {
            virtual void OnStartup() override;
            virtual void OnShutdown() override;
            virtual void OnUpdate( float dt ) override;
            virtual void OnDraw( Gem::Graphics& graphics ) override;
            virtual void OnEvent( Gem::Event event ) override;
            virtual void OnInput( Gem::Input input ) override;
        };
        typedef std::unique_ptr< Gem::Application > ApplicationPtr;
    }
}

#endif //SDLTEST_GAME_H
