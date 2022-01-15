//
// Created by annika on 15.01.2022.
//

#ifndef ALGOVIZADVENTURE_HEALTH_HPP
#define ALGOVIZADVENTURE_HEALTH_HPP



#include "../GameComponent.hpp"
#include "../ActiveGameObjects.hpp"

class Health : public GameComponent {

    int health;
    GameObject* o;

    explicit Health(ObjectStructure* ob) : GameComponent(ob){
    }

    void setHealth(int newHealth){health = newHealth;}

    void update() override {
        if(health == 0){
            ActiveGameObjects::remove(o);
        }
    }
};

#endif //ALGOVIZADVENTURE_HEALTH_HPP