// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMELOOP_HPP
#define ALGOVIZADVENTURE_GAMELOOP_HPP

#include "ActiveGameObjects.hpp"
#include "GameObject.hpp"
#include "GTime.hpp"

class GameLoop {
    ActiveGameObjects* ago;
    GameObject* player;
    GTime* gTime;

    GameLoop() = delete;

    void update() {
        for (GameObject* obj : ago->getActive())
            obj->preUpdate();
        for (GameObject* obj : ago->getActive())
            obj->update();
        for (GameObject* obj : ago->getActive())
            obj->postUpdate();
    }
public:

    explicit GameLoop(ActiveGameObjects* ago){
        this->ago = ago;
    }

    void setPlayer(GameObject* pPlayer) {player = pPlayer;}
    void setGTime(GTime *pTime) {gTime = pTime;}

    [[noreturn]] void startGameLoop() {
        for (GameObject* obj : ago->getActive())
            obj->onStart();

        gTime->setStart();
        while (true) {
            gTime->setDelta();
            update();
        }
    }

    ActiveGameObjects* getAGO() {return ago;}
    GameObject* getPlayer() {return player;}
};

#endif //ALGOVIZADVENTURE_GAMELOOP_HPP
