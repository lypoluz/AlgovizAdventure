// Created by Lypoluz (Dominik) on 15.01.2022.

#ifndef ALGOVIZADVENTURE_ENGINE_HPP
#define ALGOVIZADVENTURE_ENGINE_HPP

#include <utility>

#include "GTime.hpp"
#include "ObjectStructure.hpp"
#include "ActiveGameObjects.hpp"
#include "../AlgoWrapper.hpp"
#include "../Config.hpp"
#include "../levelSystem/Level.hpp"

class Engine {
    GTime* gTime{};
    ObjectStructure* player{};
    ObjectStructure* ui{};
    std::vector<ObjectStructure*> onTopRenderer{};
    ActiveGameObjects* ago{};
    AlgoWrapper::Window* gameWindow{};
    Config* config{};
    Level currentLevel;
    std::string nextLevelName;
    std::string linkPointName;
    bool levelReload{};
    bool holyDoc{};
    // Audio* audio;

    Engine() = default;

public:
    static Engine* getInstance() {
        static Engine instance;
        return &instance;
    }

    void setGTime(GTime* gt) {gTime = gt;}
    GTime* getGTime() {return gTime;}

    void setPlayer(ObjectStructure* p) {player = p;}
    ObjectStructure* getPlayer() {return player;}

    void setUI(ObjectStructure* u) {ui = u;}
    ObjectStructure* getUI() {return ui;}

    void setAGO(ActiveGameObjects* a) {ago = a;}
    ActiveGameObjects* getAGO() {return ago;}

    void setGameWindow(AlgoWrapper::Window* window) {gameWindow = window;}
    AlgoWrapper::Window* getGameWindow() {return gameWindow;}

    void setConfig(Config* c) {config = c;}
    Config* getConfig() {return config;}

    void setCurrentLevel(Level l) {currentLevel = std::move(l); nextLevelName = currentLevel.name;}
    Level getCurrentLevel() {return currentLevel;}
    void setNextLevelName(std::string n) {nextLevelName = std::move(n);}
    std::string getNextLevelName() {return nextLevelName;}
    void setLinkPointName(std::string n) {linkPointName = std::move(n);}
    std::string getLinkPoint() {return linkPointName;}

    void reloadLevel(bool b=true) {levelReload = b;}
    bool needReload() {return levelReload;}

    void addOnTopRenderer(ObjectStructure* renderer) {onTopRenderer.push_back(renderer);}
    void clearOnTopRenderer() {onTopRenderer.clear();}
    std::vector<ObjectStructure*> getOnTopRenderer() {return onTopRenderer;}

    void HOLYDOCUMENTATION() {holyDoc = true;}
    bool hasHOLYDOCUMENTATION() {return holyDoc;}

};

#endif //ALGOVIZADVENTURE_ENGINE_HPP
