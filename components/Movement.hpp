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
    float speed = 1;  //speed value of 2 means half the speed
    float transitionTime = 0.5;
    float timeKeeper;
    bool movable = true;
    GTime* gTime{};

public:
    void onStart() override{gTime = Engine::getInstance()->getGTime();}

    explicit Movement(ObjectStructure* os) : GameComponent(os) {
        position = ((GameObject*)gameObject)->position;
        speed = 1;
    }

    void setSpeed(float newSpeed) {speed = newSpeed;}

    void setTransitionTime(float newTransitionTime) {transitionTime = newTransitionTime;}

    float getTransitionTime() {return transitionTime;}

    // if movement is enabled and movement is more than zero, move 1
    void MoveInDirection(Vector2 direction) {
        if(movable && (direction != Vector2::zero())) {
            position->moveBy(direction.normalized());
            movable = false;
        }
    }

    // adds the time passed and enables movement if enough time has passed
    void update() override{
        timeKeeper += gTime->deltaTime();
        if (timeKeeper >= transitionTime/speed){
            timeKeeper = 0;
            movable = true;
        }
    }

};

#endif //ALGOVIZADVENTURE_MOVEMENT_HPP
