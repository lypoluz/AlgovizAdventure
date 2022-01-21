// Created by Annika on 19.01.2022.

#ifndef ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
#define ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP

#include <utility>

#include "../engine/GameComponent.hpp"
#include "SpriteRenderer.hpp"
#include "Position.hpp"

class ChangeSpriteOnMove : public GameComponent {
    Position* position{};
    SpriteRenderer* spriteRend;
    std::string downSprite{};
    std::string leftSprite{};
    std::string rightSprite{};
    std::string upSprite{};
    Vector2 lastMoveVec;


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
        Vector2 moveVec = position->facing();
        std::string newSprite = "";
        if(moveVec == Vector2::down())
            newSprite = downSprite;
        else if(moveVec == Vector2::left())
            newSprite = leftSprite;
        else if(moveVec == Vector2::right())
            newSprite = rightSprite;
        else if(moveVec == Vector2::up())
            newSprite = upSprite;
        if(spriteRend->getSpritePath() != newSprite)
            spriteRend->setSprite(newSprite);
        lastMoveVec = moveVec;
    }
};


#endif //ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
