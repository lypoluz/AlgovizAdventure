//
// Created by tobia on 23.01.2022.
//

#ifndef ALGOVIZADVENTURE_REGENITEM_HPP
#define ALGOVIZADVENTURE_REGENITEM_HPP

#include "../engine/GameComponent.hpp"
#include "abstract/Collider.hpp"
#include "../engine/Engine.hpp"
#include "Health.hpp"

class RegenItem : GameComponent {
    Collider* playerCollider;

public:
    RegenItem(ObjectStructure* os, Collider* col) : GameComponent(os) {
        playerCollider = col;
    }

    void update() override {
        if(playerCollider->collision()){
            ((Health)Engine::getInstance()->getPlayer()->getComponent("Health")).reduceHealth(-10);
            Engine::getInstance()->getAGO()->remove((GameObject*)gameObject);
        }
    }
};

#endif //ALGOVIZADVENTURE_REGENITEM_HPP
