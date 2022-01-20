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
#include "components/SpriteRenderer.hpp"
#include "Config.hpp"
#include "levelSystem/LevelParser.hpp"
#include "Logger.hpp"
#include "components/ChangeSpriteOnMove.hpp"

class GameInitializer {

    ActiveGameObjects ago{};
    AlgoWrapper::Window window{};
    GameObject* player{};
    GTime* gTime{};
    Config config;
    Level startLevel;

public:

    explicit GameInitializer(const std::map<std::string, std::string>& configMap) {
        ConfigParser cp(&configMap);

        config.expandAlgoViz = cp.stringToBoolOrDefault("expandAlgoViz", config.expandAlgoViz);
        config.fullscreen = cp.stringToBoolOrDefault("fullscreen", config.fullscreen);
        if(config.fullscreen and config.expandAlgoViz) config.windowFrameSizeFactor = 32;
        else if(config.expandAlgoViz) config.windowFrameSizeFactor = 34;

        config.windowSize = cp.stringToIntOrDefault("windowSize", config.windowSize);
        config.windowFrameSizeFactor = cp.stringToIntOrDefault("windowFrameSizeFactor", config.windowFrameSizeFactor);
        config.playerSpeed = cp.stringToFloatOrDefault("playerSpeed", config.playerSpeed);
        config.funnyEnemies = cp.stringToBoolOrDefault("funnyEnemies", config.funnyEnemies);
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
        if(config.expandAlgoViz)
            AlgoWrapper::expand();
        if(config.fullscreen)
            AlgoWrapper::enterFullscreen();
        AlgoWrapper::clear();
        Logger::log("window creation");
        window = AlgoWrapper::Window(config.windowSize,
                                     config.windowSize,
                                     config.windowFrameSizeFactor,
                                     config.windowFrameSizeFactor,
                                     "AlgoViz Adventure");

    }


    void createPlayerInstance() {
        Logger::log("create player");

        // create player instance
        player = new GameObject("Player");
        ago.add(player);

        // create position component
        auto* position = new Position(player);
        player->addPosition(position);
        player->position->moveTo(Vector2(config.windowSize/32, config.windowSize/32));

        // movement
        auto* movement = new Movement(player);
        movement->setSpeed(config.playerSpeed);
        player->addComponent(movement);

        // player input
        auto* playerInputController = new PlayerInputController(player, &window);
        player->addComponent(playerInputController);

        // player script
        auto* playerScript = new EntityScript(player, playerInputController, movement);
        player->addComponent(playerScript);


        // renderer
        auto* renderer = new SpriteRenderer(player, &window);
        renderer->setSprite("sprites/default/player_down.png");
        renderer->setSize({16,16});
        player->addComponent(renderer);

        // changeSpriteOnMove
        auto* spriteChanger = new ChangeSpriteOnMove(player, renderer);
        spriteChanger->setDownSprite("sprites/default/player_down.svg");
        spriteChanger->setLeftSprite("sprites/default/player_left.svg");
        spriteChanger->setRightSprite("sprites/default/player_right.svg");
        spriteChanger->setUpSprite("sprites/default/player_up.svg");
    }

    void loadItems() {
        Logger::log("load items");

    }

    void loadEnemies() {
        Logger::log("load enemies");

    }

    void loadLevel() {
        Logger::log("load level");
        startLevel = LevelParser::readFile("test_01.level");
    }

    void startGameLoop() {
        Logger::log("start game loop");

        Engine* engine = Engine::getInstance();
        engine->setPlayer(player);
        engine->setAGO(&ago);
        engine->setGTime(gTime);
        engine->setConfig(&config);
        engine->setGameWindow(&window);

        GameLoop gameLoop(&ago);
        gameLoop.setPlayer(player);
        gameLoop.setGTime(gTime);
        gameLoop.setStartLevel(startLevel);
        gameLoop.startGameLoop();
    }

};

#endif //ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
