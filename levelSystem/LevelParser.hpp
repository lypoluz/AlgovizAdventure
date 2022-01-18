//
// Created by tobia on 14.01.2022.
//


#ifndef ALGOVIZADVENTURE_LEVELPARSER_HPP
#define ALGOVIZADVENTURE_LEVELPARSER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Level.hpp"
#include "Roomlink.hpp"
#include <map>

class LevelParser{

public:
    // Gibt ein Level zurück
    Level readFile(std::string pathToLevel){
        // Informationen für das Level
        std::string name;
        int xSize;
        int ySize;
        std::string theme = "Default";
        std::vector <std::vector<char>> levelVector;
        std::map<char, std::string> specialSymbols;
        int iterator;
        // maybe add roomlink map

        //Lesen der Datei, je nach Marker in der Datei werden die Variablen gesetzt
        std::ifstream levelFile(pathToLevel);
        std::string currentLine;
        while (std::getline(levelFile, currentLine)){
            switch (currentLine[0]) {
                case 'N':
                    std::getline(levelFile, currentLine);
                    name = currentLine;
                    break;
                case 'S':
                    std::getline(levelFile, currentLine);
                    xSize = std::stoi(currentLine.substr(0, currentLine.find(' ')));
                    ySize = std::stoi(currentLine.substr(currentLine.find(' ')+1, currentLine.length()-1));
                    break;
                case 'T':
                    std::getline(levelFile, currentLine);
                    theme = currentLine;
                    break;
                case 'A':
                    std::getline(levelFile, currentLine);
                    iterator = std::stoi(currentLine);
                    for (int i = 0; i<iterator ; ++i) {
                        std::getline(levelFile, currentLine);
                        specialSymbols[currentLine[0]] = currentLine.substr(2,currentLine.length()-1);
                    }
                    break;
                case 'L':
                    for (int i = 0; i < ySize; ++i) {
                        std::vector<char> inputVector;
                        std::getline(levelFile, currentLine);
                        for (int j = 0; j < xSize; ++j) {
                            inputVector.push_back(currentLine[j]);
                        }
                        levelVector.push_back(inputVector);
                    }
                    break;
                default:
                    break;
            }
        }
        levelFile.close();
        return Level(name, xSize, ySize, theme, specialSymbols, levelVector);
    }

};

#endif //ALGOVIZADVENTURE_LEVELPARSER_HPP
