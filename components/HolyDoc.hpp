// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_HOLYDOC_HPP
#define ALGOVIZADVENTURE_HOLYDOC_HPP

#include "GameComponent.hpp"
#include "Collider.hpp"
#include "Engine.hpp"

class HolyDoc : public GameComponent {

    Collider* playerCollider;

public:
    HolyDoc(ObjectStructure* os, Collider* col) : GameComponent(os) {
        playerCollider = col;
    }

    void update() override {
        if(playerCollider->collision()) {
            Engine::getInstance()->HOLYDOCUMENTATION();
        }
    }
};

#endif //ALGOVIZADVENTURE_HOLYDOC_HPP
