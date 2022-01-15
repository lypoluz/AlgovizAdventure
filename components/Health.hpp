//
// Created by annika on 15.01.2022.
//

#ifndef ALGOVIZADVENTURE_HEALTH_HPP
#define ALGOVIZADVENTURE_HEALTH_HPP



#include "../GameComponent.hpp"
#include "../ActiveGameObjects.hpp"

class Health : public GameComponent {

    int health;
    gameObject* o;

    explicit Health(ObjectStructure* ob) : GameComponent(ob){
        o = gameObject;
    }

    void setHealth(int newHealth){health = newHealth;}

    void update() override {
        if(heath == 0){
            ActiveGameObjects::remove(o);
        }
    }
};

#endif //ALGOVIZADVENTURE_HEALTH_HPP