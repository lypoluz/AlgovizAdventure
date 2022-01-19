// Created by Lypoluz (Dominik) on 19.01.2022.

#ifndef ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
#define ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP

#include "GameComponent.hpp"
#include "SpriteRenderer.hpp"
#include "Position.hpp"

class ChangeSpriteOnMove : public GameComponent {
    Position* position;
    Vector2 lastPosition;
    SpriteRenderer* spriteRend;


public:
    ChangeSpriteOnMove(ObjectStructure* os, SpriteRenderer* sr) : GameComponent(os) {
        spriteRend = sr;

    }
    void onStart(){
        position = ((GameObject*)gameObject) -> position;
    }
    void postUpdate() {
        if((position -> getPosition() - lastPosition).normalized() == Vector2::down()){
            spriteRend -> setSprite("sprites/default/player_down.png");
        }
        if((position -> getPosition() - lastPosition).normalized() == Vector2::left()){
            spriteRend -> setSprite("sprites/default/player_left");
        }
        if((position -> getPosition() - lastPosition).normalized() == Vector2::right()){
            spriteRend -> setSprite("sprites/default/player_right");
        }
        if((position -> getPosition() - lastPosition).normalized() == Vector2::up()){
            spriteRend -> setSprite("sprites/default/player_up");
        }
        lastPosition = position -> getPosition();
    }
};


#endif //ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
