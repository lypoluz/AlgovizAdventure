// Created by annika on 15.01.2022.

#ifndef ALGOVIZADVENTURE_HEALTH_HPP
#define ALGOVIZADVENTURE_HEALTH_HPP



#include "../engine/GameComponent.hpp"
#include "../engine/ActiveGameObjects.hpp"
#include "../engine/Engine.hpp"
#include "../GameLoop.hpp"

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
            if(objs -> getName() == "Player") {
//                Engine::getCurrentLevel();
//                game over
//                GameLoop::buildLevel();
            }
            else{
//                entferne enemy
//                ActiveGameObjects::remove(gameObject);
            }
        }
    }
};

#endif //ALGOVIZADVENTURE_HEALTH_HPP