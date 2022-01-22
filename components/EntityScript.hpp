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

    void onStart() override {
        PathFinder pf(Engine::getInstance()->getCurrentLevel().wallArray, {4,4}, {17,5});
        Logger::logln("calc path");
        Logger::logln(" wall at 17 5: " + std::to_string(0) + ((Engine::getInstance()->getCurrentLevel().wallArray[17][5])?"T":"F"));
        pf.calculatePath();
        if (not pf.hasPath()) {
            Logger::logln("no path");
            return;
        }
        Logger::logln("tracing path");
        std::vector<Vector2> path = pf.tracePath();
        for (Vector2 v : path)
            Logger::logln(v.toString());
        Logger::logln(SVGPathFromVector2Vector(path));

    }

    void update() override {
        // movement
        movement->MoveInDirection(inputController->getMoveVector());

        // attack
        if (inputController->isAttacking())
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
