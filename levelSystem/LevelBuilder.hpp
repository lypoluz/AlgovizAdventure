//
// Created by tobia on 19.01.2022.
//

#ifndef ALGOVIZADVENTURE_LEVELBUILDER_HPP
#define ALGOVIZADVENTURE_LEVELBUILDER_HPP

#include "Level.hpp"
#include "../engine/ActiveGameObjects.hpp"
#include "../engine/Engine.hpp"
#include "../components/WallComponent.hpp"
#include "../components/SpriteRenderer.hpp"
#include "../Logger.hpp"
#include <string>
#include <map>
#include "SpecialLevelSymbols.hpp"
#include <cstdlib>


class LevelBuilder{

    static void placeWall(int x, int y, const std::string& theme, ActiveGameObjects* ago, AlgoWrapper::Window* window, bool wallSurroundings[3][3]) {
        auto* wall = new GameObject("wall" + std::to_string(x) + std::to_string(y));
        ago->add(wall);

        //instantiate position component
        auto* position = new Position(wall);

        //set position to value
        position->moveTo(x, y);

        //game object gets its position
        wall->addPosition(position);

        auto* wallComp = new WallComponent(wall);
        wall->addComponent(wallComp);

        std::string wallType = "wall_center";

        //  10
        //01  21
        //  12
        //wall_center
        if(wallSurroundings[1][0] && wallSurroundings[0][1] && wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_center";}

        //wall_bottomtop
        else if (!wallSurroundings[1][0] && wallSurroundings[0][1] && !wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_bottomtop";}

        //wall_corner_lowerleft
        else if (wallSurroundings[1][0] && !wallSurroundings[0][1] && !wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_corner_lowerleft";}

        //wall_corner_lowerright
        else if (wallSurroundings[1][0] && wallSurroundings[0][1] && !wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_corner_lowerright";}

        //wall_corner_upperleft
        else if (!wallSurroundings[1][0] && !wallSurroundings[0][1] && wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_corner_upperleft";}

        //wall_corner_upperright
        else if (!wallSurroundings[1][0] && wallSurroundings[0][1] && wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_corner_upperright";}

        //wall_down
        else if (wallSurroundings[1][0] && wallSurroundings[0][1] && !wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_down";}

        //wall_left
        else if (wallSurroundings[1][0] && !wallSurroundings[0][1] && wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_left";}

        //wall_leftright
        else if (wallSurroundings[1][0] && !wallSurroundings[0][1] && wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_leftright";}

        //wall_open_down
        else if (!wallSurroundings[1][0] && !wallSurroundings[0][1] && wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_open_down";}

        //wall_open_left
        else if (!wallSurroundings[1][0] && wallSurroundings[0][1] && !wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_open_left";}

        //wall_open_right
        else if (!wallSurroundings[1][0] && !wallSurroundings[0][1] && !wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_open_right";}

        //wall_open_up
        else if (wallSurroundings[1][0] && !wallSurroundings[0][1] && !wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_open_up";}

        //wall_right
        else if (wallSurroundings[1][0] && wallSurroundings[0][1] && wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_right";}

        //wall_up
        else if (!wallSurroundings[1][0] && wallSurroundings[0][1] && wallSurroundings[1][2] && wallSurroundings[2][1]){wallType="wall_up";}

        //wall_closed
        else if (!wallSurroundings[1][0] && !wallSurroundings[0][1] && !wallSurroundings[1][2] && !wallSurroundings[2][1]){wallType="wall_closed";}



        auto* renderer = new SpriteRenderer(wall, window);
        renderer->setSize({16,16});
        renderer->setSprite("sprites/" + theme + "/" + wallType + ".svg");
        wall->addComponent(renderer);
    }

    static void placeFloor(int x, int y, const std::string& theme, ActiveGameObjects* ago, AlgoWrapper::Window* window){
        auto* floor = new GameObject("floor" + std::to_string(x) + std::to_string(y));
        ago->add(floor);

        //instantiate position component
        auto* position = new Position(floor);

        //set position to value
        position->moveTo(x, y);

        //game object gets its position
        floor->addPosition(position);

        auto* floorComp = new WallComponent(floor);
        floor->addComponent(floorComp);

        std::string floorType ="floor1";

        int randomInt = rand() % 100;

        if (randomInt > 95) {
            floorType = "floor3";
        } else if (randomInt > 90) {
            floorType = "floor4";
        } else if (randomInt > 60) {
            floorType = "floor2";
        }

        auto* renderer = new SpriteRenderer(floor, window);
        renderer->setSize({16,16});
        renderer->setSprite("sprites/" + theme + "/" + floorType + ".svg");
        floor->addComponent(renderer);
    }

    static void placeCorridor(int x, int y, const std::string& theme, ActiveGameObjects* ago, AlgoWrapper::Window* window){
        auto* block = new GameObject("block" + std::to_string(x) + std::to_string(y));
        ago->add(block);

        //instantiate position component
        auto* position = new Position(block);

        //set position to value
        position->moveTo(x, y);

        //game object gets its position
        block->addPosition(position);

        auto* blockComp = new WallComponent(block);
        block->addComponent(blockComp);


        auto* renderer = new SpriteRenderer(block, window);
        renderer->setSize({16,16});
        renderer->setSprite("sprites/" + theme + "/corridor.svg");
        block->addComponent(renderer);
    }



public:
    static void build(Level level) {
        Logger::log("parsing level: " + level.name);
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
                                    wallSurroundings[j + 1][i + 1] = levelArray[x + j][y + i] == '#';
                                }
                            }
                        }
                        placeWall(x, y, level.theme, ago, window, wallSurroundings);
                        break;

                    case '1':
                        //place floor (to back)
                        placeFloor(x, y, level.theme, ago, window);
                        break;

                    case 'B':
                        //place black floor
                        placeCorridor(x, y, level.theme, ago, window);
                        break;

                    case 'C':
                        // crystal code
                        break;

                    case 'S':
                        // player code
                        Logger::log("setting player to " + Vector2(x,y).toString());
                        ((GameObject*)(Engine::getInstance()->getPlayer()))->position->moveTo(x, y);
                        break;

                    default:
                        // special symbol code
                        // find thing in special symbol map by character using the find function then place thing there
                        try {
                            std::string symbolSprite;
                            symbolSprite = SpecialLevelSymbols::interpretSymbol(level.specialSymbols[levelArray[x][y]]);
                            if (symbolSprite=="b"){
                                placeFloor(x,y, level.theme, ago, window);
                            } else if (symbolSprite == "a"){
                                placeCorridor(x,y,level.theme,ago,window);
                            }
                        }
                        catch(int e) {
                            //place floor
                        }
                        break;
                }
            }
        }
    }
};


#endif //ALGOVIZADVENTURE_LEVELBUILDER_HPP
