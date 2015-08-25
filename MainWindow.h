#ifndef SDLTEST_MAINWINDOW_H
#define SDLTEST_MAINWINDOW_H

#include <string>
#include <memory>
#include "SDL_Setup.h"
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
    bool checkIsEscape( SDL_Event *event );

private:
    std::shared_ptr<SDL_Setup> sdlSetup;
	bool running = true; // The game loop flag
    std::shared_ptr<Sprite> grass;
    std::shared_ptr<Actor> bob;
};

#endif //SDLTEST_MAINWINDOW_H
