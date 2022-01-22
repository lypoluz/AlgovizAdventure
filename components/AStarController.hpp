//
// Created by tobia on 13.01.2022.
//

#ifndef ALGOVIZADVENTURE_ASTARCONTROLLER_HPP
#define ALGOVIZADVENTURE_ASTARCONTROLLER_HPP

#include "EntityController.hpp"
#include "PathRenderer.hpp"
#include "../pathing/PathFinder.hpp"
#include "../engine/Engine.hpp"

class AStartController : public EntityController {

    PathRenderer* pathRenderer;
    Position* position;
    Position* playerPosition;
    Engine* e;
    Level level;

public:
    AStartController(ObjectStructure* os, PathRenderer* pr= nullptr) : EntityController(os) {
        pathRenderer = pr;
    }

    void onStart() override {
        e = Engine::getInstance();
        position = ((GameObject*)gameObject)->position;
        playerPosition = ((GameObject*)e->getPlayer())->position;
        level = e->getCurrentLevel();
    }

    void update() override {
    }


    Vector2 getMoveVector() override {
        PathFinder pf(level.wallArray, position->getPosition(), playerPosition->getPosition());
        pf.calculatePath();
        if (not pf.hasPath()) {
            Logger::logln("[" + gameObject->getName() + "][A*] no path");
            return Vector2::zero();
        }
        std::vector<Vector2> path = pf.tracePath();
        if(pathRenderer != nullptr)
            pathRenderer->setPath(SVGPathFromVector2Vector(path, 16));
        return path[0];
    }

    bool isAttacking() override {
        return false;
    }

    bool isPickingUp() override {
        return false;
    }
};


#endif //ALGOVIZADVENTURE_ASTARCONTROLLER_HPP
