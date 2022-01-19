//
// Created by tobia on 13.01.2022.
//

#ifndef ALGOVIZADVENTURE_LEVEL_HPP
#define ALGOVIZADVENTURE_LEVEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Roomlink.hpp"
#include <map>

struct Level {
    std::string name;
    std::string theme;
    std::vector <std::vector<char>> levelVector;
    std::map<char, std::string> specialSymbols;
    // maybe Add roomlink map


    Level(std::string name,std::string theme, std::map<char, std::string> specialSymbols, std::vector <std::vector<char>> levelVector) {
        this->name = name;
        this->theme = theme;
        this->levelVector = levelVector;
        this->specialSymbols = specialSymbols;
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
