// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMELOOP_HPP
#define ALGOVIZADVENTURE_GAMELOOP_HPP

#include "ActiveGameObjects.hpp"
#include "GameObject.hpp"

class GameLoop {

    ActiveGameObjects* ago;

    void update() {
        for (GameObject* obj : ago->getActive())
            obj->preUpdate();
        for (GameObject* obj : ago->getActive())
            obj->update();
        for (GameObject* obj : ago->getActive())
            obj->postUpdate();
    }

public:
    [[noreturn]] explicit GameLoop(ActiveGameObjects* ago) {
        this->ago = ago;
        for (GameObject* obj : ago->getActive()) {
            obj->onStart();
        }
        while (true) {
            update();
        }
    }


};

#endif //ALGOVIZADVENTURE_GAMELOOP_HPP
