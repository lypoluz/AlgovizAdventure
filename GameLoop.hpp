// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMELOOP_HPP
#define ALGOVIZADVENTURE_GAMELOOP_HPP

#include <utility>

#include "engine/ActiveGameObjects.hpp"
#include "engine/GameObject.hpp"
#include "engine/GTime.hpp"
#include "AlgoWrapper.hpp"
#include "levelSystem/Level.hpp"
#include "levelSystem/LevelBuilder.hpp"

class GameLoop {
    ActiveGameObjects* ago;
    GameObject* player;
    GTime* gTime;
    Level startLevel{};

    GameLoop() = delete;

    void update() {
        for (GameObject* obj : ago->getActive())
            obj->preUpdate();
        for (GameObject* obj : ago->getActive())
            obj->update();
        for (GameObject* obj : ago->getActive())
            obj->postUpdate();
    }

    void buildStartLevel() {
        AlgoWrapper::algoText("Build start level");
        LevelBuilder::build(startLevel);
    }

public:

    explicit GameLoop(ActiveGameObjects* ago){
        this->ago = ago;
    }

    void setPlayer(GameObject* pPlayer) {player = pPlayer;}
    void setGTime(GTime *pTime) {gTime = pTime;}
    void setStartLevel(Level level) {startLevel = std::move(level);}

    [[noreturn]] void startGameLoop() {
        buildStartLevel();
        for (GameObject* obj : ago->getActive())
            obj->onStart();

        gTime->setStart();
        while (true) {
            AlgoWrapper::draw();
            gTime->setDelta();

            update();
            AlgoWrapper::algoText(std::to_string(1/(gTime->deltaTime())));
        }
    }

    ActiveGameObjects* getAGO() {return ago;}
    GameObject* getPlayer() {return player;}
};

#endif //ALGOVIZADVENTURE_GAMELOOP_HPP
