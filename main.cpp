/*
main.c - Testing SDL2
http://www.squarebitstudios.tk
*/
#include <memory>
#include "MainGame.h"

int main( int argc, char *args[] )
{
    std::unique_ptr<Game::Core::MainGame> game( new Game::Core::MainGame());
    if ( !game->OnStartUp())
    {
        std::cerr << "Game haven't started up" << std::endl;
    }
    game->Loop();
    game->OnShutdown();

    return EXIT_SUCCESS;
}
