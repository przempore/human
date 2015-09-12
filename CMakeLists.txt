cmake_minimum_required(VERSION 2.8)
project(sdlTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(sdlTest ${SOURCE_FILES} MainGame.cpp
                                       MainGame.hpp
                                       Sprite.cpp
                                       Sprite.hpp
                                       Actor.cpp
                                       Actor.hpp
                                       SDL_Setup.cpp
                                       SDL_Setup.hpp
                                       Defines.hpp
                                       Application.cpp
                                       Application.hpp
                                       InputType.hpp
                                       Game.cpp
                                       Game.hpp
                                       Input.hpp
                                       Singleton.hpp
                                       Singleton.inl
                                       NonCopyable.hpp)

#configure_file(${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})