cmake_minimum_required(VERSION 3.21)
project(AlgovizAdventure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AlgovizAdventure
        GameComponent.hpp
        GameComponent.h)
