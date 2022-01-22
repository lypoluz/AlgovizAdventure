// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP
#define ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP

#include <vector>
#include "GameObject.hpp"

class ActiveGameObjects {
    std::vector<GameObject *> activeObjects;

public:
    std::vector<GameObject *> getActive() {
        return activeObjects;
    }

    void add(GameObject* obj) {
        activeObjects.push_back(obj);
    }

    void clearExceptPlayer() {
        GameObject* player;
        for (GameObject *go: activeObjects) {
            if (go->getName() == "Player") {
                player = go;
            } else {
                go->onDestroy();
                delete go;
            }
        }
        activeObjects.clear();
        add(player);
    }

};

#endif //ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP
