// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
#define ALGOVIZADVENTURE_GAMEINITIALIZER_HPP

#include <map>
#include "engine/ActiveGameObjects.hpp"
#include "AlgoWrapper.hpp"
#include "GameLoop.hpp"
#include "engine/GTime.hpp"
#include "engine/Engine.hpp"
#include "ConfigParser.hpp"
#include "Config.hpp"
#include "levelSystem/LevelParser.hpp"
#include "Logger.hpp"
#include "Prefabs.hpp"

class GameInitializer {

    ActiveGameObjects* ago{};
    AlgoWrapper::Window window{};
    GameObject* player{};
    SpriteRenderer* pRenderer;
    SpriteRenderer* aRenderer;
    GTime* gTime{};
    Config config;
    std::string startLevelPath;
    Level startLevel;
    Engine* engine;

public:

    explicit GameInitializer(const std::map<std::string, std::string>& configMap) {
        ConfigParser cp(&configMap);
        if(cp.stringToBoolOrDefault("clearLog", true)) Logger::clearFile();

        config.expandAlgoViz = cp.stringToBoolOrDefault("expandAlgoViz", config.expandAlgoViz);
        config.fullscreen = cp.stringToBoolOrDefault("fullscreen", config.fullscreen);
        if(config.fullscreen and config.expandAlgoViz) config.windowFrameSizeFactor = 32;
        else if(config.expandAlgoViz) config.windowFrameSizeFactor = 34;

        config.windowSize = cp.stringToIntOrDefault("windowSize", config.windowSize);
        config.windowFrameSizeFactor = cp.stringToIntOrDefault("windowFrameSizeFactor", config.windowFrameSizeFactor);
        config.playerSpeed = cp.stringToFloatOrDefault("playerSpeed", config.playerSpeed);
        config.funnyEnemies = cp.stringToBoolOrDefault("funnyEnemies", config.funnyEnemies);
        config.buildStartLevel = cp.stringToBoolOrDefault("buildLevel", config.buildStartLevel);
        config.levelBorder = cp.stringToBoolOrDefault("levelBorder", config.levelBorder);
        config.displayFps = cp.stringToBoolOrDefault("displayFps", config.displayFps);
        config.pathFinderPaths = cp.stringToBoolOrDefault("pathFinderPaths", config.pathFinderPaths);
        startLevelPath = cp.stringToStringOrDefault("startLevel", "test_01.level");

        engine = Engine::getInstance();
        engine->setConfig(&config);
        engine->setLinkPointName("");
        Prefabs::setEngine(engine);
    }


    void initialize() {
        createReferences();
        windowCreation();
        createPlayerInstance();
        loadLevel();
        startGameLoop();
    }

    void createReferences() {
        ago = new ActiveGameObjects();
        engine->setAGO(ago);
        gTime = new GTime();
        engine->setGTime(gTime);
        gTime->setTimeFactor();
    }

    void windowCreation() {
        if(config.expandAlgoViz)
            AlgoWrapper::expand();
        if(config.fullscreen)
            AlgoWrapper::enterFullscreen();
        AlgoWrapper::focusGame();
        AlgoWrapper::clear();
        Logger::logln("window creation");
        window = AlgoWrapper::Window(config.windowSize,
                                     config.windowSize,
                                     config.windowFrameSizeFactor,
                                     config.windowFrameSizeFactor,
                                     "AlgoViz Adventure");
        engine->setGameWindow(&window);

    }


    void createPlayerInstance() {
        Logger::logln("create player");
        Prefabs::createPlayer();

    }

    void loadLevel() {
        Logger::logln("load level");
        startLevel = LevelParser::readFile(startLevelPath);
    }

    void startGameLoop() {
        Logger::logln("start game loop");
        GameLoop gameLoop(&ago);
        gameLoop.setGTime(gTime);
        gameLoop.setStartLevel(startLevel);
        gameLoop.startGameLoop();
    }

};

#endif //ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
