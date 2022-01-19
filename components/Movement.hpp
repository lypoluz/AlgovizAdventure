// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_MOVEMENT_HPP
#define ALGOVIZADVENTURE_MOVEMENT_HPP

#include "../engine/GameComponent.hpp"
#include "Position.hpp"
#include "../engine/GameObject.hpp"
#include "../engine/GTime.hpp"
#include "../GameLoop.hpp"
#include "../AlgoWrapper.hpp"
#include "../engine/Engine.hpp"

class Movement : public GameComponent {

    Position* position;
    float speed = 1;  //speed value of 2 means twice the speed
    float timeKeeper;
    bool movable = true;
    Vector2 startPosition;
    Vector2 targetPosition;
    GTime* gTime{};


public:
    explicit Movement(ObjectStructure* os) : GameComponent(os) {
        position = ((GameObject*)gameObject)->position;
        speed = 1;
        startPosition = Vector2::zero();
        targetPosition = Vector2::zero();
    }

    void onStart() override{gTime = Engine::getInstance()->getGTime();}

    void setSpeed(float newSpeed) {speed = newSpeed;}
    bool canMove() {return movable;};

    // if movement is enabled and movement is more than zero, move 1
    void MoveInDirection(Vector2 direction) {
        if(movable && (direction != Vector2::zero())) {
            startPosition = position->getPosition();
            targetPosition = position->getPosition() + direction.normalized();
            movable = false;
        }
    }

    // adds the time passed and enables movement if enough time has passed
    void update() override{
        if (timeKeeper >= 1/speed){
            timeKeeper = 0;
            movable = true;
        } else {
            timeKeeper += gTime->deltaTime();
        }
        if(not movable) {
            position->moveTo(Vector2::lerp(startPosition, targetPosition, timeKeeper*speed));
        }
    }

};

#endif //ALGOVIZADVENTURE_MOVEMENT_HPP
