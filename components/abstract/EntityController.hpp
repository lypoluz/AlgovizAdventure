// Created by Lypoluz (Dominik) on 15.01.2022.

#ifndef ALGOVIZADVENTURE_ENTITYCONTROLLER_HPP
#define ALGOVIZADVENTURE_ENTITYCONTROLLER_HPP

#include "GameComponent.hpp"
#include "Vector2.hpp"

class EntityController : public GameComponent {

public:
    EntityController(ObjectStructure* os) : GameComponent(os) {}

    virtual Vector2 getMoveVector() = 0;
    virtual bool isAttacking() = 0;
    virtual bool isPickingUp() = 0;

};


#endif //ALGOVIZADVENTURE_ENTITYCONTROLLER_HPP
