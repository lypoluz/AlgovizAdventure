// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP
#define ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP

#include <vector>
class GameObject;

class ActiveGameObjects {
    std::vector<GameObject *> activeObjects;

public:
    std::vector<GameObject *> getActive() {
        return activeObjects;
    }

    void add(GameObject* obj) {
        activeObjects.push_back(obj);
    }

    void remove(GameObject* obj) {

    }
};

#endif //ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP
