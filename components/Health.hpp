// Created by annika on 15.01.2022.

#ifndef ALGOVIZADVENTURE_HEALTH_HPP
#define ALGOVIZADVENTURE_HEALTH_HPP



#include "../engine/GameComponent.hpp"
#include "../engine/ActiveGameObjects.hpp"

class Health : public GameComponent {

    int health;
    ObjectStructure* objs;

public:
    explicit Health(ObjectStructure* os) : GameComponent(os) {
        objs = os;
    }

    void setHealth(int newHealth) {health = newHealth;}

    void update() override {
        if (health == 0) {
            if(objs ==){
//                game over
            }
            else{
//                entferne enemy
//                ActiveGameObjects::remove(gameObject);
            }
            GameObject* player;
            for (GameObject *go: activeObjects) {
                if (go->getName() == "Player") {
                    player = go;
                } else {
                    go->onDestroy();
                    delete go;
                }
            }
        }
    }
};

#endif //ALGOVIZADVENTURE_HEALTH_HPP