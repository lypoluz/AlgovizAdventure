// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
#define ALGOVIZADVENTURE_GAMEINITIALIZER_HPP

#include "ActiveGameObjects.hpp"
#include "AlgoWrapper.hpp"
#include "components/Movement.hpp"
#include "components/PlayerInputController.hpp"
#include "GameLoop.hpp"
#include "components/CircleRenderer.hpp"
#include "components/EntityScript.hpp"

class GameInitializer {

    ActiveGameObjects ago;
    int windowSize = 1000;
    AlgoWrapper::Window window;
    float playerSpeed = 1;

public:
    GameInitializer() {
        ago = ActiveGameObjects();
        windowCreation();
        createPlayerInstance();
        loadItems();
        loadEnemies();
        loadLevel();
        startGameLoop();
    }

    void windowCreation() {
        AlgoWrapper::clear();
        AlgoWrapper::algoText("window creation");
        window = AlgoWrapper::Window(windowSize, windowSize, "scene");
    }


    void createPlayerInstance() {
        AlgoWrapper::algoText("create player");

        // create player instance
        auto* player = new GameObject("Player");
        ago.add(player);

        // create position component
        auto* position = new Position(player);
        player->addPosition(position);
        player->position->moveTo(Vector2(100, 100));

        // movement
        auto* movement = new Movement(player);
        movement->setSpeed(playerSpeed);
        player->addComponent(movement);

        // player input
        auto* playerInputController = new PlayerInputController(player, &window);
        player->addComponent(playerInputController);

        // player script
        auto* playerScript = new EntityScript(player, playerInputController, movement);
        player->addComponent(playerScript);

        // renderer
        auto* renderer = new CircleRenderer(player, &window);
        renderer->setFill(0,0,255);
        renderer->setRadius(windowSize/20);
        player->addComponent(renderer);

    }

    void loadItems() {
        AlgoWrapper::algoText("load items");

    }

    void loadEnemies() {
        AlgoWrapper::algoText("load enemies");

    }

    void loadLevel() {
        AlgoWrapper::algoText("load level");

    }

    void startGameLoop() {
        AlgoWrapper::algoText("start game loop");

        GameLoop gameLoop(&ago);



    }

};

#endif //ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
