// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_WEAPON_HPP
#define ALGOVIZADVENTURE_WEAPON_HPP


#include "engine/GameComponent.hpp"

class Weapon : public GameComponent {
public:
    Weapon(ObjectStructure* os) : GameComponent(os) {}

    virtual void performAttack() = 0;
};



#endif //ALGOVIZADVENTURE_WEAPON_HPP
