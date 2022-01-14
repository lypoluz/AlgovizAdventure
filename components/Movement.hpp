// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_MOVEMENT_HPP
#define ALGOVIZADVENTURE_MOVEMENT_HPP

#include "GameComponent.hpp"
#include "Position.hpp"
#include "GameObject.hpp"

class Movement : public GameComponent {

    Position* position;
    float speed;


public:
    Movement(ObjectStructure* os) : GameComponent(os) {
        position = ((GameObject*)gameObject)->position;
        speed = 1;
    }

    void setSpeed(float newSpeed) {speed = newSpeed;}
    void MoveInDirection(Vector2 direction) {
        position->moveBy(direction.normalized()*speed);
    }

};

#endif //ALGOVIZADVENTURE_MOVEMENT_HPP
