// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_PLAYER_HPP
#define ALGOVIZADVENTURE_PLAYER_HPP


#include <utility>

#include "GameObject.hpp"

class Player : public GameObject {

    explicit Player(Position* posComp, std::vector<GameComponent *> comps=std::vector<GameComponent*>{}) : GameObject() {
        position = posComp;
        components = std::move(comps);
    }

};


#endif //ALGOVIZADVENTURE_PLAYER_HPP
