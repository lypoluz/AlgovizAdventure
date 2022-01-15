// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_MOVEMENT_HPP
#define ALGOVIZADVENTURE_MOVEMENT_HPP

#include "../GameComponent.hpp"
#include "Position.hpp"
#include "../GameObject.hpp"
#include "../GTime.hpp"
#include "../GameLoop.hpp"
#include "../AlgoWrapper.hpp"
#include "../Engine.hpp"

class Movement : public GameComponent {

    Position* position;
    float speed;


public:
    explicit Movement(ObjectStructure* os) : GameComponent(os) {
        position = ((GameObject*)gameObject)->position;
        speed = 1;
    }

    void setSpeed(float newSpeed) {speed = newSpeed;}
    void MoveInDirection(Vector2 direction) {
        GTime* gTime = Engine::getInstance()->getGTime();
        AlgoWrapper::algoText(std::to_string(gTime->deltaTime()));
        position->moveBy(direction.normalized()*speed*gTime->deltaTime());
    }

};

#endif //ALGOVIZADVENTURE_MOVEMENT_HPP
