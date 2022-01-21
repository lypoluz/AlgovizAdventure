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
#include "Logger.hpp"

class GameLoop {
    ActiveGameObjects* ago;
    Renderer* playerRenderer;
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
        if(not Engine::getInstance()->getConfig()->buildStartLevel) return;
        Logger::log("Build start level");
        AlgoWrapper::draw();
        LevelBuilder::build(startLevel);
        playerRenderer->toFront();
    }

public:

    explicit GameLoop(ActiveGameObjects* ago){
        this->ago = ago;
    }

    void setPlayerRenderer(Renderer* pr) {playerRenderer = pr;}
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
            //AlgoWrapper::algoText(std::to_string(1/(gTime->deltaTime())));
        }
    }

};

#endif //ALGOVIZADVENTURE_GAMELOOP_HPP
