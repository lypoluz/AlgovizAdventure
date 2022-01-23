// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP
#define ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP

#include <vector>
#include "GameObject.hpp"

class ActiveGameObjects {
    std::vector<GameObject *> activeObjects;
    std::vector<GameObject *> attackables;

public:
    void add(GameObject* obj) {activeObjects.push_back(obj);}
    std::vector<GameObject *> getActive() {return activeObjects;}

    void addAttackable(GameObject* obj) { add(obj); attackables.push_back(obj);}
    std::vector<GameObject *> getAttackables() {return attackables;}

    void remove(GameObject* obj) {

        for(int i=0; i<activeObjects.size(); ++i) {
            if(activeObjects[i] == obj) {
                activeObjects[i]->onDestroy();
                activeObjects.erase(activeObjects.begin() + i);
                break;
            }
        }

        // attackables
        for(int i=0; i<attackables.size(); ++i) {
            if(attackables[i] == obj) {
                attackables[i]->onDestroy();
                attackables.erase(attackables.begin() + i);
                break;
            }
        }

        // no memory leak
        delete obj;
    }

    void clearAll() {
        for (GameObject *go: activeObjects) {
                go->onDestroy();
        }
        activeObjects.clear();
        attackables.clear();
    }

};

#endif //ALGOVIZADVENTURE_ACTIVEGAMEOBJECTS_HPP
