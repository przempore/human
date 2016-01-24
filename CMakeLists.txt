cmake_minimum_required(VERSION 3.3)
project(human)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(human ${SOURCE_FILES}   Sprite.cpp
                                       Sprite.h
                                       Actor.cpp
                                       Actor.h
                                       SDL_Setup.cpp
                                       SDL_Setup.h
                                       Defines.h
                                       Application.cpp
                                       Application.h
                                       Game.cpp
                                       Game.h
                                       Input.h Event.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/gem/src")
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
