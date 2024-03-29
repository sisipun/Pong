cmake_minimum_required(VERSION 3.14)
project(Pong)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB
        #GAME
        src/game/game.cpp

        #UTILS
        src/util/constants.h
        src/util/time/timer.cpp
        src/util/physics/body.h
        src/util/physics/collision.cpp

        #CHARACTER
        src/character/block.cpp
        src/character/player.cpp
        src/character/enemy.cpp
        src/character/ball.cpp
        )

add_library(Components STATIC ${SOURCE_LIB})
add_executable(SuperMario ${SOURCE_EXE})

target_link_libraries(Components ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})
target_link_libraries(SuperMario Components)