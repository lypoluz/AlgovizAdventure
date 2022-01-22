//
// Created by tobia on 13.01.2022.
//

#ifndef ALGOVIZADVENTURE_LEVEL_HPP
#define ALGOVIZADVENTURE_LEVEL_HPP

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

struct Level {
    std::string name{};
    std::string theme{};
    std::vector <std::vector<char>> levelVector{};
    std::map<char, std::string> specialSymbols{};
    bool wallArray[30][30];
    // maybe Add roomlink map


    Level() = default;
    Level(std::string name,std::string theme, std::map<char, std::string> specialSymbols, std::vector <std::vector<char>> levelVector) {
        this->name = std::move(name);
        this->theme = std::move(theme);
        this->levelVector = levelVector;
        this->specialSymbols = std::move(specialSymbols);

        for(int x=0; x<30; ++x)
            for(int y=0; y<30; ++y)
                wallArray[x][y] = levelVector[y][x] == '#';
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
