#ifndef SDLTEST_MAINWINDOW_H
#define SDLTEST_MAINWINDOW_H

#include <stdbool.h>
#include <string>
#include <memory>
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Actor.h"
#include "Game.h"

namespace Game
{
    namespace Core
    {
        class MainGame
        {
        public:
            MainGame();
            virtual ~MainGame();

        public:
            bool OnStartUp();
            void Loop();
            void OnShutdown();

        private:
            bool CheckIsEscape( SDL_Event *event );
            void CheckSDLEvent( SDL_Event *event );

        private:
            ApplicationPtr application;
            std::shared_ptr<Components::Core::SDL_Setup> sdlSetup;
            _Bool running = true; // The game loop flag
            std::shared_ptr<Components::Graphics::Sprite> grass;
            std::shared_ptr<Actor> bob;
        };
    }
}
#endif //SDLTEST_MAINWINDOW_H
