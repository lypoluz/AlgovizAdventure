// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_MOVEMENT_HPP
#define ALGOVIZADVENTURE_MOVEMENT_HPP

#include "../GameComponent.hpp"
#include "Position.hpp"
#include "../GameObject.hpp"
#include "../GTime.hpp"
#include "../GameLoop.hpp"


class Movement : public GameComponent {

    Position* position;
    float speed;
    GTime* gTime{};


public:
    explicit Movement(ObjectStructure* os) : GameComponent(os) {
        position = ((GameObject*)gameObject)->position;
        speed = 1;
    }

    void onStart() override {
        gTime = GameLoop::getGameLoop()->getGTime();
    }

    void setSpeed(float newSpeed) {speed = newSpeed;}
    void MoveInDirection(Vector2 direction) {
        position->moveBy(direction.normalized()*speed*gTime->deltaTime());
    }

};

#endif //ALGOVIZADVENTURE_MOVEMENT_HPP
