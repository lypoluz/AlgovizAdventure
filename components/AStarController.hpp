//
// Created by tobia on 13.01.2022.
//

#ifndef ALGOVIZADVENTURE_ASTARCONTROLLER_HPP
#define ALGOVIZADVENTURE_ASTARCONTROLLER_HPP

#include "EntityController.hpp"

class AStartController : public EntityController {



    



public:
    Vector2 getMoveVector() override {
        return Vector2();
    }

    bool isAttacking() override {
        return false;
    }

    bool isPickingUp() override {
        return false;
    }
};


#endif //ALGOVIZADVENTURE_ASTARCONTROLLER_HPP
