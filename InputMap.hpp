// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_INPUTMAP_HPP
#define ALGOVIZADVENTURE_INPUTMAP_HPP

#include <string>
#include <utility>

struct InputMap {
    std::string down;
    std::string up;
    std::string right;
    std::string left;
    std::string attack;
    std::string pickUp;

    explicit InputMap(
            std::string down   = "s",
            std::string up     = "w",
            std::string right  = "d",
            std::string left   = "a",
            std::string attack = " ",
            std::string pickUp = "f") :
            down(std::move(down)),
            up(std::move(up)),
            right(std::move(right)),
            left(std::move(left)),
            attack(std::move(attack)),
            pickUp(std::move(pickUp)){}
};

#endif //ALGOVIZADVENTURE_INPUTMAP_HPP
