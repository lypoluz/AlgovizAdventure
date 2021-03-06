// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_POSITION_HPP
#define ALGOVIZADVENTURE_POSITION_HPP

#include "../engine/GameComponent.hpp"
#include "../Vector2.hpp"
#include "../Logger.hpp"

class Position : public GameComponent {
    Vector2 lastPosition;
    Vector2 position;
    Vector2 lastFacing;
    float rotation{};
    bool dirty = true;

    void updateFacing() {
        Vector2 facing = (position-lastPosition).normalized();
        lastFacing = (facing == Vector2::zero()) ? lastFacing : facing;
    }

public:
    explicit Position(ObjectStructure *os) : GameComponent(os) {}

    void preUpdate() override { dirty = false; }

    std::string getName() override { return "Position"; }

    Vector2 facing() { return lastFacing;}
    Vector2 getPosition() { return position; }
    float x() { return position.x(); }
    float y() { return position.y(); }
    float getRotation() const { return rotation; }

    void moveTo(float x, float y) { moveTo({x,y}); }
    void moveTo(Vector2 newPos) {
        if(gameObject->getName() == "Player")
            Logger::logln("[POS] moving Player to " + newPos.toString());
        lastPosition = position;
        position = newPos;
        dirty = true;
        updateFacing();
    }

    void moveBy(float x, float y) { moveBy({x,y}); }
    void moveBy(Vector2 amount) {moveTo(position+amount);}

    void setFacing(Vector2 direction) {lastFacing = direction.normalized();}
    void rotateBy(float angle) { rotateTo(rotation+angle); }
    void rotateTo(float angle) {
        rotation = angle;
        dirty = true;
    }

    void setDirty() {dirty = true;}
    bool isDirty() const { return dirty; }
};

#endif //ALGOVIZADVENTURE_POSITION_HPP
