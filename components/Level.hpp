//
// Created by tobia on 13.01.2022.
//

#include <iostream>
#include <string>
#include <vector>

#ifndef ALGOVIZADVENTURE_LEVEL_HPP
#define ALGOVIZADVENTURE_LEVEL_HPP

struct Level {
    std::string name;
    int xSize;
    int ySize;
    std::string theme;
    vector <vector<char>> levelVector;


    Level(std::string name, int xSize, int ySize, std::string theme, vector <vector<char>> levelVector) {
        this->name = name;
        this->xSize = xSize;
        this->ySize = ySize;
        this->levelVector = levelVector;
    }

    // Gibt einen Character an der Gewünschten Position zurück
    char getCharAt(int x, int y){
        return levelVector
    }

};



#endif //ALGOVIZADVENTURE_LEVEL_HPP
