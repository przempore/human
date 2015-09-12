//
// Created by przemo on 01.09.15.
//

#ifndef SDLTEST_GAME_H
#define SDLTEST_GAME_H


#include <memory>
#include "Application.hpp"
#include "Sprite.hpp"
#include "Actor.hpp"

namespace Game
{
    namespace Core
    {
        class Game : public Application
        {
        public:
            Game();
            virtual ~Game();
        private:
            virtual void OnStartup() override;
            virtual void OnShutdown() override;
            virtual void OnUpdate( float dt ) override;
            virtual void OnDraw( SDL_Renderer *renderer ) override;
            virtual void OnEvent( SDL_Event type,
                                  void *event ) override;
            virtual void OnInput( InputType type,
                                  void *input ) override;

        private:
            std::shared_ptr<Components::Graphics::Sprite> grass;
            std::shared_ptr<Actor> bob;
        };

        typedef std::unique_ptr<Application> ApplicationPtr;
    }
}

#endif //SDLTEST_GAME_H
