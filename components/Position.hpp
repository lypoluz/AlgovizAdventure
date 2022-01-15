// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_POSITION_HPP
#define ALGOVIZADVENTURE_POSITION_HPP

#include "../GameComponent.hpp"
#include "../Vector2.hpp"
#include "../AlgoWrapper.hpp"

class Position : public GameComponent {
    Vector2 position;
    float rotation;
    bool dirty{};

public:
    explicit Position(ObjectStructure* os) : GameComponent(os) {
        position = Vector2::zero();
        rotation = 0;
    }

    void preUpdate() override {dirty = false;}
    std::string getName() override {return "Position";}

    Vector2 getPosition() {return position;}
    float x() {return position.x();}
    float y() {return position.y();}
    int getRotation() {return rotation;}

    void moveTo(Vector2 newPos) {position = newPos; dirty = true;}
    void moveTo(float x, float y) { moveTo(Vector2(x,y));}
    void moveBy(Vector2 amount) {position += amount; dirty = true;}
    void moveBy(float x, float y) {moveBy(Vector2(x,y));}

    void rotateTo(float angle) {rotation = angle; dirty = true;}
    void rotateBy(float angle) {rotation += angle;}

    bool isDirty() {return dirty;}
};

#endif //ALGOVIZADVENTURE_POSITION_HPP
