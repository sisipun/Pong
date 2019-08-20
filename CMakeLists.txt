cmake_minimum_required(VERSION 3.14)
project(Pong)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB
        src/game/game.cpp
        src/util/constants.h
        src/character/block.cpp)

add_library(Components STATIC ${SOURCE_LIB})
add_executable(SuperMario ${SOURCE_EXE})

target_link_libraries(Components ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES})
target_link_libraries(SuperMario Components)