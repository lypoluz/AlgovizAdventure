// Created by annika on 15.01.2022.

#ifndef ALGOVIZADVENTURE_HEALTH_HPP
#define ALGOVIZADVENTURE_HEALTH_HPP



#include "../engine/GameComponent.hpp"
#include "../engine/Engine.hpp"

class Health : public GameComponent {

    int health;

public:
    explicit Health(ObjectStructure* os) : GameComponent(os) {}

    std::string getName() override {return "Health";}

    void setHealth(int newHealth) {
        health = newHealth;
        if (health <= 0) {
            if(gameObject -> getName() == "Player") {
                Engine::getInstance()->reloadLevel();
            }
            else{
                Engine::getInstance()->getAGO()->remove((GameObject*) gameObject);
            }
        }
    }
};

#endif //ALGOVIZADVENTURE_HEALTH_HPP