// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
#define ALGOVIZADVENTURE_GAMEINITIALIZER_HPP

#include <map>
#include "engine/ActiveGameObjects.hpp"
#include "AlgoWrapper.hpp"
#include "components/Movement.hpp"
#include "components/PlayerInputController.hpp"
#include "GameLoop.hpp"
#include "components/CircleRenderer.hpp"
#include "components/EntityScript.hpp"
#include "engine/GTime.hpp"
#include "engine/Engine.hpp"
#include "ConfigParser.hpp"

class GameInitializer {

    ActiveGameObjects ago{};
    AlgoWrapper::Window window{};
    GameObject* player{};
    GTime* gTime{};

public:
    int windowSize = 1000;
    float playerSpeed = 150;
    bool funnyEnemies = false;

    explicit GameInitializer(const std::map<std::string, std::string>& config) {
        ConfigParser cp(&config);
        windowSize = cp.stringToIntOrDefault("windowSize", windowSize);
        playerSpeed = cp.stringToFloatOrDefault("playerSpeed", playerSpeed);
        funnyEnemies = cp.stringToBoolOrDefault("funnyEnemies", funnyEnemies);
    }


    void initialize() {
        createReferences();
        windowCreation();
        createPlayerInstance();
        loadItems();
        loadEnemies();
        loadLevel();
        startGameLoop();
    }

    void createReferences() {
        ago = ActiveGameObjects();
        gTime = new GTime();
        gTime->setTimeFactor();
    }

    void windowCreation() {
        AlgoWrapper::clear();
        AlgoWrapper::algoText("window creation");
        window = AlgoWrapper::Window(windowSize, windowSize, "scene");
    }


    void createPlayerInstance() {
        AlgoWrapper::algoText("create player");

        // create player instance
        player = new GameObject("Player");
        ago.add(player);

        // create position component
        auto* position = new Position(player);
        player->addPosition(position);
        player->position->moveTo(Vector2(windowSize/2, windowSize/2));

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

        Engine* engine = Engine::getInstance();
        engine->setPlayer(player);
        engine->setAGO(&ago);
        engine->setGTime(gTime);

        GameLoop gameLoop(&ago);
        gameLoop.setPlayer(player);
        gameLoop.setGTime(gTime);
        gameLoop.startGameLoop();
    }

};

#endif //ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
