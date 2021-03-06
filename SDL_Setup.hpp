#ifndef SDLTEST_SDL_SETUP_H
#define SDLTEST_SDL_SETUP_H

#include <SDL2/SDL.h>
#include "Singleton.hpp"

namespace Components
{
    namespace Core
    {
        class SDL_Setup
        {
        public:
            SDL_Setup();
            virtual ~SDL_Setup();

        public:
            SDL_Event *GetEvent()
            { return event; }

            SDL_Renderer *GetRendere()
            { return renderer; }

        private:
            SDL_Window *window = nullptr; // the window
            SDL_Event *event = new SDL_Event(); // The event structure
            SDL_Renderer *renderer = nullptr;
        };
    }
}

#endif //SDLTEST_SDL_SETUP_H
