/*
main.c - Testing SDL2
http://www.squarebitstudios.tk
*/
#include <memory>
#include "MainWindow.h"

int main( int argc, char *args[] )
{
    std::unique_ptr<MainWindow> window( new MainWindow());
    window->Loop();

    return 0;
}
