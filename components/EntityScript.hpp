// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_ENTITYSCRIPT_HPP
#define ALGOVIZADVENTURE_ENTITYSCRIPT_HPP


#include <utility>
#include "../engine/GameComponent.hpp"
#include "PlayerInputController.hpp"
#include "Movement.hpp"
#include "abstract/Weapon.hpp"


class EntityScript : public GameComponent {
    EntityController* inputController;
    Movement* movement;
    Weapon* currentWeapon;
    /*Inventory* inventory;
    float pickUpRadius = 1;

    Item* lookForItem() {
        // check if an item is in range
        // return that item
        return nullptr;
    }*/

public:
    EntityScript(ObjectStructure* os, EntityController* ec, Movement* m/*, Inventory* i*/) : GameComponent(os) {
        inputController = ec;
        movement = m;
        //inventory = i;
    }

    void update() override {
        // movement
        movement->MoveInDirection(inputController->getMoveVector());

        // attack
        if (inputController->isAttacking() && currentWeapon)
            currentWeapon->performAttack();

        /*/ pickup
        if(inputController->isPickingUp()) {
            Item* item = lookForItem();
            if(item)
                inventory->pickUpItem(item);
        }*/
    }


};

#endif //ALGOVIZADVENTURE_ENTITYSCRIPT_HPP
