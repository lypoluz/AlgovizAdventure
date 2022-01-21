// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_MOVEMENT_HPP
#define ALGOVIZADVENTURE_MOVEMENT_HPP

#include <algorithm>
#include "../engine/GameComponent.hpp"
#include "Position.hpp"
#include "../engine/GameObject.hpp"
#include "../engine/GTime.hpp"
#include "../GameLoop.hpp"
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

    void onStart() override{gTime = Engine::getInstance()->getGTime();}

    void setSpeed(float newSpeed) {speed = newSpeed;}
    bool canMove() {return movable;};

    // if movement is enabled and movement is more than zero, move 1
    void MoveInDirection(Vector2 direction) {
        if(movable && (direction != Vector2::zero())) {
            startPosition = position->getPosition();
            targetPosition = startPosition + direction.normalized();
            movable = false;
            timer = 0;
        }
    }

    // adds the time passed and enables movement if enough time has passed
    void update() override{
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
