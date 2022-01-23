// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_MOVEMENT_HPP
#define ALGOVIZADVENTURE_MOVEMENT_HPP

#include <algorithm>
#include "../engine/GameComponent.hpp"
#include "Position.hpp"
#include "../engine/GameObject.hpp"
#include "../engine/GTime.hpp"
#include "../AlgoWrapper.hpp"
#include "../engine/Engine.hpp"
#include "../Ease.hpp"

class Movement : public GameComponent {

    Position* position;
    float speed = 1;
    float timer;
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

    void onStart() override {
        gTime = Engine::getInstance()->getGTime();
        timer = 10/speed;
        movable = true;
        startPosition = position->getPosition();
        targetPosition = startPosition;
    }

    void setSpeed(float newSpeed) {speed = newSpeed;}
    bool canMove() {return movable;};

    // if movement is enabled and movement is more than zero, move 1
    void MoveInDirection(Vector2 direction) {
        if(not movable) return;
        if(direction == Vector2::zero()) return;
        direction = direction.normalized();
        Vector2 newPos = position->getPosition() + direction;
        if(newPos.x() < 0 or newPos.x() >= 30 or newPos.y() < 0 or newPos.y() >= 30 or
            Engine::getInstance()->getCurrentLevel().wallArray[(int)newPos.x()][(int)newPos.y()]) {
            position->setFacing(direction);
            return;
        }
        if(position->facing() != direction) {
            newPos = targetPosition;
            position->setFacing(direction);
            timer = 14 / ( 15 * speed);
        } else {
            timer = 0;
        }

        startPosition = position->getPosition();
        targetPosition = newPos;
        movable = false;
    }

    // adds the time passed and enables movement if enough time has passed
    void update() override{
        if(Engine::getInstance()->getConfig()->funnyEnemies and gameObject->getName()!="Player")
            timer *= 2;
        timer += gTime->deltaTime();
        if(not movable) {
            if (timer >= 1 / speed) {
                movable = true;
                position->moveTo(targetPosition);
            } else {
                // easing function
                float x = Ease::InOutQuart(std::min(timer * speed, 1.0f));
                // calculation a point between start end target based on x
                position->moveTo(Vector2::lerp(startPosition, targetPosition, x));
            }
        }
    }

};

#endif //ALGOVIZADVENTURE_MOVEMENT_HPP
