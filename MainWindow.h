#ifndef SDLTEST_MAINWINDOW_H
#define SDLTEST_MAINWINDOW_H

#include <stdbool.h>
#include <string>
#include <memory>
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Actor.h"

namespace Game
{
    namespace Core
    {
        class MainWindow
        {
        public:
            MainWindow();

            virtual ~MainWindow();

        public:
            void Loop();

        private:
            bool checkIsEscape( SDL_Event *event );

        private:
            std::shared_ptr<Components::Core::SDL_Setup> sdlSetup;
            _Bool running = true; // The game loop flag
            std::shared_ptr<Components::Graphics::Sprite> grass;
            std::shared_ptr<Actor> bob;
        };
    }
}
#endif //SDLTEST_MAINWINDOW_H
