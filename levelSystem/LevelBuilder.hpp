//
// Created by tobia on 19.01.2022.
//

#ifndef ALGOVIZADVENTURE_LEVELBUILDER_HPP
#define ALGOVIZADVENTURE_LEVELBUILDER_HPP

#include "Level.hpp"
#include "../engine/ActiveGameObjects.hpp"
#include "../engine/Engine.hpp"
#include "../Logger.hpp"
#include "../components/RoomLink.hpp"
#include "../Prefabs.hpp"
#include <string>
#include <map>
#include <cstdlib>
#include <utility>


class LevelBuilder{

public:
    static void build(Level level, const std::string& newPlayerLocation = "noLink") {
        int secureSpawnX, secureSpawnY;
        bool secureSpawn = true;
        Logger::logln("parsing level: " + level.name);
        char levelArray[30][30];
        ActiveGameObjects* ago = Engine::getInstance()->getAGO();
        AlgoWrapper::Window* window = Engine::getInstance()->getGameWindow();

        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                levelArray[j][i] = level.levelVector[i][j];
            }
        }

        for (int y = 0; y < 30; ++y) {
            for (int x = 0; x < 30; ++x) {

                switch (levelArray[x][y]) {
                    case '#':
                        // wall code
                        bool wallSurroundings[3][3];
                        for (int i = -1; i <= 1; ++i) {
                            for (int j = -1; j <= 1; ++j) {
                                if (x+j < 0 || x+j >= 30 || y+i < 0 || y+i >= 30){
                                    wallSurroundings[j+1][i+1] = !Engine::getInstance()->getConfig()->levelBorder;
                                }else {
                                    wallSurroundings[j + 1][i + 1] = level.wallArray[x + j][y + i];
                                }
                            }
                        }
                        Prefabs::create().wall(x, y, level.theme, wallSurroundings);
                        break;

                    case '1':
                        //place floor (to back)
                        Prefabs::create().floor(x, y, level.theme);
                        break;

                    case 'B':
                        //place black floor
                        Prefabs::create().corridor(x, y, level.theme);
                        break;

                    case 'C':
                        // crystal code
                        Prefabs::create().floor(x, y, level.theme);
                        break;

                    case 'S':
                        // player code
                        Prefabs::create().floor(x, y, level.theme);
                        secureSpawnX = x;
                        secureSpawnY = y;
                        if (newPlayerLocation == "noLink") {
                            Logger::logln("[LB] setting player to " + Vector2(x, y).toString());
                            ((GameObject *) (Engine::getInstance()->getPlayer()))->position->moveTo(x, y);
                            secureSpawn = false;
                        }
                        break;

                    case 'E':
                        // Test Enemy
                        Prefabs::create().floor(x, y, level.theme);
                        Prefabs::create().ghost(x, y);
                        break;

                    default:
                        // special symbol code
                        // find thing in special symbol map by character using the find function then place thing there

                        std::string symbol = level.specialSymbols[levelArray[x][y]].substr(0, level.specialSymbols[levelArray[x][y]].find(' ') );

                        if (symbol == "roomlink") {
                            //roomLink code
                            // roomlink [targetLevel] [linkPoint] -> targetLevel
                            // roomlink [targetLevel] [linkPoint] -> [targetLevel] [linkPoint]-> [linkPoint]
                            Prefabs::create().floor(x, y, level.theme);
                            std::string roomlinkInfo = level.specialSymbols[levelArray[x][y]].substr(level.specialSymbols[levelArray[x][y]].find(' ')+1, level.specialSymbols[levelArray[x][y]].length()-1);
                            std::string targetLevel = roomlinkInfo.substr(0, roomlinkInfo.find(' '));
                            std::string linkPoint = roomlinkInfo.substr(roomlinkInfo.find(' ')+1, roomlinkInfo.length()-1);
                            Prefabs::create().roomLink(x, y, targetLevel, linkPoint);
                        }else if (symbol == "linkPoint") {
                            //linkPoint code
                            //get linkPoint from new levelBuilder parameter check if they're equal then place player
                            //player code
                            Prefabs::create().floor(x, y, level.theme);
                            if (newPlayerLocation == level.specialSymbols[levelArray[x][y]].substr(level.specialSymbols[levelArray[x][y]].find(' ')+1, level.specialSymbols[levelArray[x][y]].length()-1)){
                                Logger::logln("[LB] setting player to " + Vector2(x, y).toString());
                                ((GameObject *) (Engine::getInstance()->getPlayer()))->position->moveTo(x, y);
                                secureSpawn = false;
                            }
                        }else if (symbol == "enemy") {
                            //enemies code
                            Prefabs::create().floor(x, y, level.theme);
                            Prefabs::create().ghost(x, y);
                        }else if (symbol == "item") {
                            //item code
                            Prefabs::create().floor(x, y, level.theme);
                            if("blocker" == level.specialSymbols[levelArray[x][y]].substr(level.specialSymbols[levelArray[x][y]].find(' ')+1, level.specialSymbols[levelArray[x][y]].length()-1)){
                                // blocker code
                                if (!Engine::getInstance()->hasHOLYDOCUMENTATION()) {
                                    Prefabs::create().blocker(x, y);
                                    level.wallArray[x][y] = true;
                                    Engine::getInstance()->setCurrentLevel(level);
                                }
                            }else if("holy_documentation" == level.specialSymbols[levelArray[x][y]].substr(level.specialSymbols[levelArray[x][y]].find(' ')+1, level.specialSymbols[levelArray[x][y]].length()-1)){
                                // holy documentation code
                                if(!Engine::getInstance()->hasHOLYDOCUMENTATION()) Prefabs::create().holyDocumentation(x, y);
                            }
                        }

                        break;
                }
            }
        }
        if (secureSpawn){
            Logger::logln("[LB] ALERT! secure spawn used! setting player to " + Vector2(secureSpawnX, secureSpawnY).toString());
            ((GameObject *) (Engine::getInstance()->getPlayer()))->position->moveTo(secureSpawnX, secureSpawnY);
        }
    }
};


#endif //ALGOVIZADVENTURE_LEVELBUILDER_HPP
