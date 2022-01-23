// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_HOLYDOC_HPP
#define ALGOVIZADVENTURE_HOLYDOC_HPP

#include "../engine/GameComponent.hpp"
#include "abstract/Collider.hpp"
#include "../engine/Engine.hpp"

class HolyDoc : public GameComponent {

    Collider* playerCollider;

public:
    HolyDoc(ObjectStructure* os, Collider* col) : GameComponent(os) {
        playerCollider = col;
    }

    void update() override {
        if(playerCollider->collision()) {
            Engine::getInstance()->HOLYDOCUMENTATION();
            Engine::getInstance()->getAGO()->remove((GameObject*)gameObject);
        }
    }
};

#endif //ALGOVIZADVENTURE_HOLYDOC_HPP
