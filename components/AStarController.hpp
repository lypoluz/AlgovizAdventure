//
// Created by tobia on 13.01.2022.
//

#ifndef ALGOVIZADVENTURE_ASTARCONTROLLER_HPP
#define ALGOVIZADVENTURE_ASTARCONTROLLER_HPP

#include "abstract/EntityController.hpp"
#include "PathRenderer.hpp"
#include "../pathing/PathFinder.hpp"
#include "../engine/Engine.hpp"

class AStarController : public EntityController {

    PathRenderer* pathRenderer;
    Position* position;
    Position* playerPosition;
    Engine* e;
    Level level;

public:
    AStarController(ObjectStructure* os, PathRenderer* pr= nullptr) : EntityController(os) {
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
        if (pathRenderer != nullptr) {
            std::string d = SVGPathFromVector2Vector(path, 16, .5);
            pathRenderer->setPath(d); }
        path.erase(path.begin());
        Vector2 direction = (path[0] - position->getPosition()).normalized();
        return direction;
    }

    bool isAttacking() override {
        // returns true if enemy is close enough to player
        return (playerPosition->getPosition() - position->getPosition()).magnitude() < 0.7;
    }


};


#endif //ALGOVIZADVENTURE_ASTARCONTROLLER_HPP
