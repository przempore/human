#ifndef SDLTEST_MAINWINDOW_H
#define SDLTEST_MAINWINDOW_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <string>
#include <memory>
#include "Sprite.h"
#include "Actor.h"

class MainWindow
{
public:
    MainWindow();

    virtual ~MainWindow();

public:
    void Loop();

private:
    SDL_Window *window = nullptr; // the window
    SDL_Event *event = new SDL_Event(); // The event structure
    SDL_Renderer *renderer = nullptr;
    _Bool m_running = true; // The game loop flag
    std::shared_ptr<Sprite> grass;
    std::shared_ptr<Actor> bob;
    const int m_windowWidth = 800;
    const int m_windowHeight = 600;
    const char *m_windowTitle = "Human game";
};

#endif //SDLTEST_MAINWINDOW_H
