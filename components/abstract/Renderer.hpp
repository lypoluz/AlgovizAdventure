// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_RENDERER_HPP
#define ALGOVIZADVENTURE_RENDERER_HPP

#include "../../engine/GameComponent.hpp"
#include "../../engine/GameObject.hpp"
#include "../../AlgoWrapper.hpp"
#include "../../Logger.hpp"

class Renderer : public GameComponent {
protected:
    Position* position;
    Vector2 positionOffset;
    int rotationOffset;
    AlgoWrapper::WindowElement* element{};
    AlgoWrapper::Window* window;
    bool front{};

    Renderer(ObjectStructure *os, AlgoWrapper::Window* win) : GameComponent(os) {
        position = ((GameObject *) gameObject)->position;
        window = win;
        positionOffset = Vector2::zero();
        rotationOffset = 0;
    }

    void updateView() {
        auto* go = (GameObject*) gameObject;
        Vector2 viewPosition = (position->getPosition() + positionOffset + Vector2(.5, .5)) * 16;
        element->moveTo(viewPosition);
        element->rotateTo(position->getRotation() + rotationOffset);
        if(front) element->toFront();
    }


public:
    void onStart() override {
        updateView();
    }
    void postUpdate() override {
        if (position->isDirty()) updateView();
    }

    void onDestroy() override {
        element->removeFromView();
    }

    void setPositionOffset(Vector2 offset) {positionOffset = offset;}
    void setRotationOffset(int offset) {rotationOffset = offset;}

    void toFront() {element->toFront();}
    void show() {try{element->show();}catch (std::exception&) {}}
    void hide() {element->hide();}
    void forceToFront(bool b=true) {front = b;}

};

#endif //ALGOVIZADVENTURE_RENDERER_HPP
