// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_PLAYERSCRIPT_HPP
#define ALGOVIZADVENTURE_PLAYERSCRIPT_HPP


#include <utility>

#include "../GameComponent.hpp"
#include "InputController.hpp"
#include "Movement.hpp"
#include "abstract/Weapon.hpp"


class PlayerScript : public GameComponent {
    InputController* inputController;
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
    PlayerScript(ObjectStructure* os, InputController* ic, Movement* m/*, Inventory* i*/) : GameComponent(os) {
        inputController = ic;
        movement = m;
        //inventory = i;
    }

    void update() override {
        // movement
        movement->MoveInDirection(inputController->getInputVector());

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

    void switchInputMap(InputMap newInputMap) {inputController->switchInputMap(std::move(newInputMap));}


};

#endif //ALGOVIZADVENTURE_PLAYERSCRIPT_HPP
