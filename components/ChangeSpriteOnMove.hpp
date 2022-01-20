// Created by Annika on 19.01.2022.

#ifndef ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
#define ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP

#include <utility>

#include "../engine/GameComponent.hpp"
#include "SpriteRenderer.hpp"
#include "Position.hpp"

class ChangeSpriteOnMove : public GameComponent {
    Position* position{};
    Vector2 lastPosition1;
    Vector2 lastPosition2;
    Vector2 lastPosition3;
    SpriteRenderer* spriteRend;
    std::string downSprite{};
    std::string leftSprite{};
    std::string rightSprite{};
    std::string upSprite{};


public:
    ChangeSpriteOnMove(ObjectStructure* os, SpriteRenderer* sr) : GameComponent(os) {
        spriteRend = sr;
    }

    void setDownSprite(std::string path) {downSprite = std::move(path);}
    void setLeftSprite(std::string path) {leftSprite = std::move(path);}
    void setRightSprite(std::string path) {rightSprite = std::move(path);}
    void setUpSprite(std::string path) {upSprite = std::move(path);}

    void onStart() override {
        position = ((GameObject*)gameObject) -> position;
    }

    void postUpdate() override {
        Vector2 moveVec = (position -> getPosition() - lastPosition3).normalized();
        AlgoWrapper::algoText(position-> getPosition().toString() + " - " + lastPosition3.toString() + " .norm() = " + moveVec.toString());
        if(moveVec == Vector2::down()){
            spriteRend -> setSprite(downSprite);
        }
        else if(moveVec == Vector2::left()){
            spriteRend -> setSprite(leftSprite);
        }
        else if(moveVec == Vector2::right()){
            spriteRend -> setSprite(rightSprite);
        }
        else if(moveVec == Vector2::up()){
            spriteRend -> setSprite(upSprite);
        }
        lastPosition3 = lastPosition2;
        lastPosition2 = lastPosition1;
        lastPosition1 = position -> getPosition();
    }
};


#endif //ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
