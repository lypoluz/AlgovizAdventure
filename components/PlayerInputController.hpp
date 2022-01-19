// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_PLAYERINPUTCONTROLLER_HPP
#define ALGOVIZADVENTURE_PLAYERINPUTCONTROLLER_HPP

#include <utility>

#include "../engine/GameComponent.hpp"
#include "../Vector2.hpp"
#include "../AlgoWrapper.hpp"
#include "../InputMap.hpp"
#include "abstract/EntityController.hpp"


class PlayerInputController : public EntityController {
    Vector2 currentVec;
    Vector2 lastVec;
    AlgoWrapper::Window* window;
    InputMap inputMap{};
    std::string lastKey;

public:
    PlayerInputController(ObjectStructure * os, AlgoWrapper::Window* win) : EntityController(os) {
        currentVec = Vector2::zero();
        lastVec = Vector2::zero();
        window = win;
        lastKey = "";
    }

    void preUpdate() override {
        lastVec = currentVec;
        currentVec = Vector2::zero();
        lastKey = window->lastKey();

        if     (lastKey == inputMap.down)  currentVec = Vector2::down();
        else if(lastKey == inputMap.up)    currentVec = Vector2::up();
        else if(lastKey == inputMap.right) currentVec = Vector2::right();
        else if(lastKey == inputMap.left)  currentVec = Vector2::left();
    }


    void switchInputMap(InputMap newInputMap) {inputMap = std::move(newInputMap);}

    Vector2 getMoveVector() override {return (currentVec + lastVec).normalized();}
    bool isAttacking() override {return lastKey == inputMap.attack;}
    bool isPickingUp() override {return lastKey == inputMap.pickUp;}
    std::string getRawInput() {return lastKey;}
};

#endif //ALGOVIZADVENTURE_PLAYERINPUTCONTROLLER_HPP
