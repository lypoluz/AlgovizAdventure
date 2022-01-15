//
// Created by tobia on 13.01.2022.
//

#ifndef ALGOVIZADVENTURE_LEVEL_HPP
#define ALGOVIZADVENTURE_LEVEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include "../Roomlink.hpp"


struct Level {
    std::string name;
    int xSize;
    int ySize;
    std::string theme;
    std::vector <std::vector<char>> levelVector;
    // todo Add roomlink map
    // todo Add special symbol map

    Level(std::string name, int xSize, int ySize, std::string theme, std::vector <std::vector<char>> levelVector) {
        this->name = name;
        this->xSize = xSize;
        this->ySize = ySize;
        this->theme = theme;
        this->levelVector = levelVector;
    }

    // Gibt einen Character an der gewünschten Position zurück
    char trueCharAt(int x, int y){
        return levelVector[x][y];
    }

    char getCharAt(int x, int y){
        return levelVector[y][x];
    }
};



#endif //ALGOVIZADVENTURE_LEVEL_HPP
