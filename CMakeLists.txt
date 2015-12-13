cmake_minimum_required(VERSION 2.8)
project(human)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(human ${SOURCE_FILES} MainGame.cpp
                                       MainGame.h
                                       Sprite.cpp
                                       Sprite.h
                                       Actor.cpp
                                       Actor.h
                                       SDL_Setup.cpp
                                       SDL_Setup.h
                                       Defines.h
                                       Application.cpp
                                       Application.h
                                       InputType.h Game.cpp Game.h Input.h)

#configure_file(${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})