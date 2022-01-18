//
// Created by annika on 15.01.2022.
//

#ifndef ALGOVIZADVENTURE_HEALTH_HPP
#define ALGOVIZADVENTURE_HEALTH_HPP



#include "../engine/GameComponent.hpp"
#include "../engine/ActiveGameObjects.hpp"

class Health : public GameComponent {

    int health;

public:
    explicit Health(ObjectStructure* os) : GameComponent(os) {}

    void setHealth(int newHealth) {health = newHealth;}

    void update() override {
        if (health == 0) {
//            ActiveGameObjects::remove(gameObject);
        }
    }
};

#endif //ALGOVIZADVENTURE_HEALTH_HPP