// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMELOOP_HPP
#define ALGOVIZADVENTURE_GAMELOOP_HPP

#include "ActiveGameObjects.hpp"

class GameLoop {

    ActiveGameObjects* ago;

    GameLoop(ActiveGameObjects* ago) {
        this->ago = ago;
    }

    void update() {
        for (GameObject* obj : ago->getActive()) {obj->preUpdate();}
        for (GameObject* obj : ago->getActive()) {obj->update();}
        for (GameObject* obj : ago->getActive()) {obj->postUpdate();}
    }


};

#endif //ALGOVIZADVENTURE_GAMELOOP_HPP
