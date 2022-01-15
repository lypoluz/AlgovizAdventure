cmake_minimum_required(VERSION 3.21)
project(AlgovizAdventure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(components)
include_directories(components/abstract)
include_directories(examples)

add_executable(AlgovizAdventure
        components/abstract/EntityController.hpp
        components/abstract/Renderer.hpp
        components/abstract/Weapon.hpp
        components/BasicAi.hpp
        components/CircleRenderer.hpp
        components/EntityScript.hpp
        components/Health.hpp
        components/Movement.hpp
        components/PlayerInputController.hpp
        components/Position.hpp
        components/SpriteRenderer.hpp
        examples/CreateEnemyExample.hpp
        examples/CreateTestComponent.hpp
        examples/test.hpp
        ActiveGameObjects.hpp
        AlgoWrapper.hpp
        AudioPlayer.hpp
        Engine.hpp
        GameComponent.hpp
        GameInitializer.hpp
        GameLoop.hpp
        GameObject.hpp
        GTime.hpp
        InputMap.hpp
        Level.hpp
        LevelParser.hpp
        ObjectStructure.hpp
        Roomlink.hpp
        utils.cpp
        Vector2.hpp)
