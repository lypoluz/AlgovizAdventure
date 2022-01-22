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
#include "levelSystem/LevelParser.hpp"

class GameLoop {
    ActiveGameObjects* ago;
    std::vector<Renderer*> toFrontRenderer;
    GTime* gTime;
    Level currentLevel{};
    bool displayFps;
    Engine* e;


    GameLoop() = delete;

    void update() {
        for (GameObject* obj : ago->getActive())
            obj->preUpdate();
        for (GameObject* obj : ago->getActive())
            obj->update();
        for (GameObject* obj : ago->getActive())
            obj->postUpdate();
    }

    void buildLevel() {
        if(not Engine::getInstance()->getConfig()->buildStartLevel) return;
        Engine::getInstance()->setCurrentLevel(currentLevel);
        Logger::logln("Build level " + currentLevel.name);
        AlgoWrapper::draw();
        LevelBuilder::build(currentLevel);
    }

    void toFront() {
        for (Renderer* r : toFrontRenderer)
            r->toFront();
    }

    bool newLevel() {
        return e->getCurrentLevel().name != e->getNextLevelName();
    }

public:

    explicit GameLoop(ActiveGameObjects* ago){
        this->ago = ago;
        e = Engine::getInstance();
        displayFps = e->getConfig()->displayFps;
    }

    void addToFrontRenderer(Renderer* pr) {toFrontRenderer.push_back(pr);}
    void setGTime(GTime *pTime) {gTime = pTime;}
    void setStartLevel(Level level) { currentLevel = std::move(level);}

    [[noreturn]] void startGameLoop() {
        buildLevel();
        toFront();

        for (GameObject* obj : ago->getActive())
            obj->onStart();

        Logger::logln("[GL] actually starting game loop");
        gTime->setStart();

        while (not newLevel()) {
            AlgoWrapper::draw();
            gTime->setDelta();

            update();
            if(displayFps)
                AlgoWrapper::algoText(std::to_string(1/(gTime->deltaTime())) + " fps");
        }

        e->getGameWindow()->clear();
        currentLevel = LevelParser::readFile(e->getNextLevelName());
        LevelBuilder::build(currentLevel, e->getLinkPoint());
    }

};

#endif //ALGOVIZADVENTURE_GAMELOOP_HPP
