/*
main.c - Testing SDL2
http://www.squarebitstudios.tk
*/
#include <memory>
#include "MainGame.h"

int main( int argc, char *args[] )
{
    std::unique_ptr<Game::Core::MainGame> game( new Game::Core::MainGame());
    game->OnStartUp();
    game->Loop();
    game->OnShutdown();

    return EXIT_SUCCESS;
}
