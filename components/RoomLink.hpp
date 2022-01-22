//
// Created by tobia on 12.01.2022.
//
#ifndef ALGOVIZADVENTURE_ROOMLINK_HPP
#define ALGOVIZADVENTURE_ROOMLINK_HPP

#include <string>
#include <utility>
#include "../engine/GameComponent.hpp"
#include "../engine/Engine.hpp"
#include "abstract/Collider.hpp"

class RoomLink : public GameComponent {
    Collider* playerCollider;
    std::string targetLevel;
    std::string targetPoint;

public:
    RoomLink(ObjectStructure* os, Collider* pCol) : GameComponent(os) {
        playerCollider = pCol;
    }

    void setTargetLevel(std::string tLevel) { targetLevel = std::move(tLevel);}
    void setTargetPoint(std::string tPoint) { targetPoint = std::move(tPoint);}

    void update() override {
        if(playerCollider->collision()) {
            Engine::getInstance()->setNextLevelName(targetLevel);
            Engine::getInstance()->setLinkPointName(targetPoint);
        }
    }

};

#endif