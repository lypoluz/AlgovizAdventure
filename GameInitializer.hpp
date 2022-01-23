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
    GTime* gTime{};
    Config config;
    std::string startLevelPath;
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
        startLevelPath = cp.stringToStringOrDefault("startLevel", "start.level");
    }


    void initialize() {
        createReferences();
        windowCreation();
        Prefabs::create().setEngine(engine);
        createPlayerInstance();
        loadLevel();
        startGameLoop();
    }

private:
    void createReferences() {
        engine = Engine::getInstance();
        engine->setConfig(&config);
        engine->setLinkPointName("");

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
        Prefabs::create().player();
    }

    void loadLevel() {
        Logger::logln("load level");
        engine->setCurrentLevel(LevelParser::readFile(startLevelPath));
    }


// Game loop things

    void update() {
        for (GameObject* obj : ago->getActive())
            obj->preUpdate();
        for (GameObject* obj : ago->getActive())
            obj->update();
        for (GameObject* obj : ago->getActive())
            obj->postUpdate();
    }

    void buildLevel() {
        Level currentLevel = engine->getCurrentLevel();
        if(not engine->getConfig()->buildStartLevel) return;
        Logger::logln("Build level " + currentLevel.name);
        AlgoWrapper::draw();
        if(engine->getLinkPoint().empty())
            LevelBuilder::build(currentLevel);
        else
            LevelBuilder::build(currentLevel, engine->getLinkPoint());
    }

    void toFront() {
        for (ObjectStructure *r : engine->getOnTopRenderer())
            ((Renderer*)r)->toFront();
    }

    bool newLevel() {
        return engine->getCurrentLevel().name != engine->getNextLevelName() or engine->needReload();
    }

    void startGameLoop() {
        buildLevel();
        toFront();
        AlgoWrapper::draw();

        for (GameObject* obj : ago->getActive())
            obj->onStart();

        Logger::logln("[GL] actually starting game loop");
        gTime->setStart();

        while (not newLevel()) {
            AlgoWrapper::draw();
            gTime->setDelta();

            update();
            if(config.displayFps)
                AlgoWrapper::algoText(std::to_string(1/(gTime->deltaTime())) + " fps");
        }

        engine->getGameWindow()->clear();
        engine->clearOnTopRenderer();
        ago->clearAll();
        engine->setCurrentLevel(LevelParser::readFile(engine->getNextLevelName()));
        createPlayerInstance();
        startGameLoop();
    }

};

#endif //ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
