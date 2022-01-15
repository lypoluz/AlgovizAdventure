// Created by Lypoluz (Dominik) on 15.01.2022.

#ifndef ALGOVIZADVENTURE_ENGINE_HPP
#define ALGOVIZADVENTURE_ENGINE_HPP

#include "GTime.hpp"
#include "ObjectStructure.hpp"
#include "ActiveGameObjects.hpp"

class Engine {
    GTime* gTime{};
    ObjectStructure* player{};
    ActiveGameObjects* ago;
    // Audio* audio;

    Engine() = default;

public:
    static Engine* getInstance() {
        static Engine instance;
        return &instance;
    }

    void setGTime(GTime* gt) {gTime = gt;}
    GTime* getGTime() {return gTime;}

    void setPlayer(GameObject* p) {player = p;}
    ObjectStructure* getPlayer() {return player;}

    void setAGO(ActiveGameObjects* a) {ago = a;}
    ActiveGameObjects* getAGO() {return ago;}

};

#endif //ALGOVIZADVENTURE_ENGINE_HPP
