//
// Created by przemo on 01.09.15.
//

#ifndef SDLTEST_GAME_H
#define SDLTEST_GAME_H


#include <memory>
#include "Application.h"

namespace Game
{
    namespace Core
    {
        class Game : public Application
        {
            virtual void OnStartup() override;
            virtual void OnShutdown() override;
            virtual void OnUpdate( float dt ) override;
            virtual void OnDraw( SDL_Renderer *renderer ) override;
            virtual void OnEvent( Event event ) override;
            virtual void OnInput( Input input ) override;
        };
        typedef std::unique_ptr< Application > ApplicationPtr;
    }
}

#endif //SDLTEST_GAME_H
