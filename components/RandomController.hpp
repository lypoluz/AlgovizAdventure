//
// Created by tobia on 23.01.2022.
//

#ifndef ALGOVIZADVENTURE_RANDOMCONTROLLER_HPP
#define ALGOVIZADVENTURE_RANDOMCONTROLLER_HPP

#include "abstract/EntityController.hpp"
#include <random>

class RandomController: public EntityController{

    int random;


public:

    RandomController(ObjectStructure * os) : EntityController(os) {

    }

    Vector2 getMoveVector() override {

        random = rand() % 100;

        if (random > 80) return Vector2::up();
        if (random > 60) return Vector2::down();
        if (random > 40) return Vector2::left();
        if (random > 20) return Vector2::right();

        return Vector2::zero();

    }

    bool isAttacking() override {
        return false;
    }

};

#endif //ALGOVIZADVENTURE_RANDOMCONTROLLER_HPP
