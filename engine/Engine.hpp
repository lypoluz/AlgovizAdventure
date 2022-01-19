// Created by Lypoluz (Dominik) on 15.01.2022.

#ifndef ALGOVIZADVENTURE_ENGINE_HPP
#define ALGOVIZADVENTURE_ENGINE_HPP

#include "GTime.hpp"
#include "ObjectStructure.hpp"
#include "ActiveGameObjects.hpp"
#include "../AlgoWrapper.hpp"
#include "../Config.hpp"

class Engine {
    GTime* gTime{};
    ObjectStructure* player{};
    ActiveGameObjects* ago;
    AlgoWrapper::Window* gameWindow{};
    Config* config;
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

    void setAGO(ActiveGameObjects* a) {ago = a;}
    ActiveGameObjects* getAGO() {return ago;}

    void setGameWindow(AlgoWrapper::Window* window) {gameWindow = window;}
    AlgoWrapper::Window* getGameWindow() {return gameWindow;}

    void setConfig(Config* c) {config = c;}
    Config* getConfig() {return config;}
};

#endif //ALGOVIZADVENTURE_ENGINE_HPP
