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


class LevelBuilder{

    static void placeWall(int x, int y, const std::string& theme, ActiveGameObjects* ago, AlgoWrapper::Window* window) {
        Logger::log("GameObject");
        GameObject* wall = new GameObject("wall" + std::to_string(x) + std::to_string(y));
        ago->add(wall);

        //instantiate position component
        Logger::log("Position");
        Position* position = new Position(wall);

        //set position to value
        position->moveTo(x, y);

        //game object gets its position
        wall->addPosition(position);

        Logger::log("wallComp");
        WallComponent* wallComp = new WallComponent(wall);
        wall->addComponent(wallComp);

        Logger::log("Renderer");
        auto* renderer = new SpriteRenderer(wall, window);
        renderer->setSprite("sprites/" + theme + "/wall_01.png");
        renderer->setSize({16,16});
        Logger::log("addComp");
        wall->addComponent(renderer);
        Logger::log("after");
    }

public:
    static void build(Level level) {
        char levelArray[30][30];
        ActiveGameObjects* ago = Engine::getInstance()->getAGO();
        AlgoWrapper::Window* window = Engine::getInstance()->getGameWindow();

        Logger::log(level.name);
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                levelArray[j][i] = level.levelVector[i][j];
            }
        }

        Logger::log("switch");
        for (int y = 0; y < 30; ++y) {
            for (int x = 0; x < 30; ++x) {

                switch (levelArray[x][y]) {
                    case '#':
                        Logger::log("#");
                        placeWall(x, y, level.theme, ago, window);
                        break;

                    case ' ':
                        //empty code
                        break;

                    case 'C':
                        //crystal code
                        break;

                    case 'S':
                        //player code
                        break;

                    default:
                        //special symbol code
                        break;
                }

            }

        }
    }



};


#endif //ALGOVIZADVENTURE_LEVELBUILDER_HPP