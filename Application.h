//
// Created by przemo on 31.08.15.
//

#ifndef SDLTEST_APPLICATION_H
#define SDLTEST_APPLICATION_H


#include <SDL_render.h>
#include <SDL_events.h>
#include "InputType.h"

namespace Game
{
    namespace Core
    {
        class Application
        {
        public:
            Application();
            virtual ~Application();

        public:
            virtual void OnStartup() = 0;
            virtual void OnShutdown() = 0;
            virtual void OnUpdate( float dt ) = 0;
            virtual void OnDraw( SDL_Renderer *renderer ) = 0;
            virtual void OnEvent( SDL_Event type,
                                  void *event ) = 0;
            virtual void OnInput( InputType type,
                                  void *input ) = 0;

        public:
            void Quit();
        };
    }
}


#endif //SDLTEST_APPLICATION_H
