cmake_minimum_required(VERSION 3.21)
project(AlgovizAdventure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        GameComponent.hpp
        components/Position.hpp
        GameInitializer.hpp
        GameLoop.hpp
        ActiveGameObjects.hpp
        AlgoWrapper.hpp
        examples/CreateEnemyExample.hpp
        examples/CreateTestComponent.hpp
        ObjectStructure.hpp

        )
