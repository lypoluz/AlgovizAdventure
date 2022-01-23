// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_ENTITYSCRIPT_HPP
#define ALGOVIZADVENTURE_ENTITYSCRIPT_HPP


#include <utility>
#include "../engine/GameComponent.hpp"
#include "PlayerInputController.hpp"
#include "Movement.hpp"
#include "AttackAnimator.hpp"
#include "../pathing/PathFinder.hpp"
#include "Attacker.hpp"


class EntityScript : public GameComponent {
    EntityController* inputController;
    Movement* movement;
    AttackAnimator* attackAnimator;
    Attacker* attacker;

public:
    EntityScript(ObjectStructure* os, EntityController* ec, Movement* m, AttackAnimator* aa, Attacker* a) : GameComponent(os) {
        inputController = ec;
        movement = m;
        attackAnimator = aa;
        attacker = a;
    }

    void update() override {
        // movement
        if(movement->canMove())
            movement->MoveInDirection(inputController->getMoveVector());

        // attack
        if (inputController->isAttacking()) {
            if (attackAnimator != nullptr)
                attackAnimator->startAnimation();
            if (attacker != nullptr)
                attacker->attack();
        }
    }


};

#endif //ALGOVIZADVENTURE_ENTITYSCRIPT_HPP
