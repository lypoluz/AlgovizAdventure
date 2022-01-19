// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_RENDERER_HPP
#define ALGOVIZADVENTURE_RENDERER_HPP

#include "../../engine/GameComponent.hpp"
#include "../../engine/GameObject.hpp"
#include "../../AlgoWrapper.hpp"

class Renderer : public GameComponent {
protected:
    Position* position;
    Vector2 positionOffset;
    int rotationOffset;
    AlgoWrapper::WindowElement* element;
    AlgoWrapper::Window* window;

    Renderer(ObjectStructure *os, AlgoWrapper::Window* win) : GameComponent(os) {
        position = ((GameObject *) gameObject)->position;
        window = win;
        positionOffset = Vector2::zero();
        rotationOffset = 0;
    }


public:
    void postUpdate() override {
        if (position->isDirty()) {
            element->moveTo((position->getPosition() + positionOffset) * 16);
            element->rotateTo(position->getRotation() + rotationOffset);
        }
    }

    void onDestroy() override {
        element->removeFromView();
    }

    void setPositionOffset(Vector2 offset) {positionOffset = offset;}
    void setRotationOffset(int offset) {rotationOffset = offset;}

    void toFront() {element->toFront();}
    void show() {element->show();}
    void hide() {element->hide();}

};

#endif //ALGOVIZADVENTURE_RENDERER_HPP
