cmake_minimum_required(VERSION 3.3)
project(human)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Actor.cpp
    Actor.h
    Application.cpp
    Application.h
    Application.inl
    DebugInfo.h
    Defines.h
    Event.h
    Game.cpp
    Game.h
    Input.h
    main.cpp
    MainGame.cpp
    MainGame.h
    SDL_Setup.cpp
    SDL_Setup.h
    Sprite.cpp
    Sprite.h)

add_executable(human ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
