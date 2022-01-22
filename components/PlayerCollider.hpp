// Created by Lypoluz (Dominik) on 22.01.2022.

#ifndef ALGOVIZADVENTURE_PLAYERCOLLIDER_HPP
#define ALGOVIZADVENTURE_PLAYERCOLLIDER_HPP

#include "abstract/Collider.hpp"
#include "Position.hpp"
#include "../engine/GameObject.hpp"
#include "../engine/Engine.hpp"

class PlayerCollider : public Collider {

    Position* position;
    Position* playerPosition;

public:
    PlayerCollider(ObjectStructure* os) : Collider(os) {}

    void onStart() override {
        position = ((GameObject*) gameObject)->position;
        playerPosition = ((GameObject*)Engine::getInstance()->getPlayer())->position;
    }

    bool collision() override {
        return (position->getPosition() - playerPosition->getPosition()).magnitude() < .5;
    }
};

#endif //ALGOVIZADVENTURE_PLAYERCOLLIDER_HPP
