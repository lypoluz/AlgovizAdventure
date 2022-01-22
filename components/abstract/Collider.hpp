// Created by Lypoluz (Dominik) on 22.01.2022.

#ifndef ALGOVIZADVENTURE_COLLIDER_HPP
#define ALGOVIZADVENTURE_COLLIDER_HPP

#include "../../engine/GameComponent.hpp"

class Collider : public GameComponent {

public:
    Collider(ObjectStructure* os) : GameComponent(os) {}

    virtual bool collision() = 0;
};

#endif //ALGOVIZADVENTURE_COLLIDER_HPP
