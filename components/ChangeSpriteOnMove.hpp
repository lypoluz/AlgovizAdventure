// Created by Lypoluz (Dominik) on 19.01.2022.

#ifndef ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
#define ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP

#include "GameComponent.hpp"
#include "SpriteRenderer.hpp"

class ChangeSpriteOnMove : public GameComponent {

public:
    ChangeSpriteOnMove(ObjectStructure* os, SpriteRenderer* sr) : GameComponent(os) {

    }

    void postUpdate() {

    }

};


#endif //ALGOVIZADVENTURE_CHANGESPRITEONMOVE_HPP
