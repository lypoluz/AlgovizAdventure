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
    AlgoWrapper::WindowElement* element;
    AlgoWrapper::Window* window;

    Renderer(ObjectStructure *os, AlgoWrapper::Window* win) : GameComponent(os) {
        position = ((GameObject *) gameObject)->position;
        window = win;
        positionOffset = Vector2::zero();
        rotationOffset = 0;
    }

    void updateView() {
        auto* go = (GameObject*) gameObject;
        Vector2 viewPosition = (position->getPosition() + positionOffset + Vector2(.5, .5)) * 16;
        Logger::log("[" + debugName + "] rendering " + go->getName() +
                    "_" + std::to_string(go->getId()) +
                    " at " + viewPosition.toString() +
                    " with position " + position->getPosition().toString() +
                    " + offset " + positionOffset.toString()
        );
        element->moveTo(viewPosition);
        element->rotateTo(position->getRotation() + rotationOffset);
    }


public:

    std::string debugName = "Renderer";

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
    void show() {element->show();}
    void hide() {element->hide();}

};

#endif //ALGOVIZADVENTURE_RENDERER_HPP
