/*
main.c - Testing SDL2
http://www.squarebitstudios.tk
*/
#include <memory>
#include "MainWindow.h"

int main( int argc, char *args[] )
{
    std::unique_ptr<Game::Core::MainWindow> window( new Game::Core::MainWindow());
    window->Loop();

    return 0;
}
