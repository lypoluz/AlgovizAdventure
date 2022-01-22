// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_ENTITYSCRIPT_HPP
#define ALGOVIZADVENTURE_ENTITYSCRIPT_HPP


#include <utility>
#include "../engine/GameComponent.hpp"
#include "PlayerInputController.hpp"
#include "Movement.hpp"
#include "AttackAnimator.hpp"
#include "../pathing/PathFinder.hpp"


class EntityScript : public GameComponent {
    EntityController* inputController;
    Movement* movement;
    AttackAnimator* attackAnimator;
    /*Inventory* inventory;
    float pickUpRadius = 1;

    Item* lookForItem() {
        // check if an item is in range
        // return that item
        return nullptr;
    }*/

public:
    EntityScript(ObjectStructure* os, EntityController* ec, Movement* m, AttackAnimator* aa/*, Inventory* i*/) : GameComponent(os) {
        inputController = ec;
        movement = m;
        attackAnimator = aa;
        //inventory = i;
    }

    void update() override {
        // movement
        if(movement->canMove())
            movement->MoveInDirection(inputController->getMoveVector());

        // attack
        if (inputController->isAttacking() and attackAnimator != nullptr)
            attackAnimator->startAnimation();

        /*/ pickup
        if(inputController->isPickingUp()) {
            Item* item = lookForItem();
            if(item)
                inventory->pickUpItem(item);
        }*/
    }


};

#endif //ALGOVIZADVENTURE_ENTITYSCRIPT_HPP
