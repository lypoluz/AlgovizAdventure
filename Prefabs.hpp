// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_PREFABS_HPP
#define ALGOVIZADVENTURE_PREFABS_HPP

#include "Engine.hpp"
#include "SpriteRenderer.hpp"
#include "ChangeSpriteOnMove.hpp"
#include "AttackAnimator.hpp"
#include "Movement.hpp"
#include "PlayerInputController.hpp"
#include "EntityScript.hpp"
#include "WallComponent.hpp"
#include "PlayerCollider.hpp"
#include "RoomLink.hpp"
#include "PathRenderer.hpp"
#include "AStarController.hpp"

class Prefabs {
    static Engine* e;
    static ActiveGameObjects* ago;
    static AlgoWrapper::Window* window;
    static Config* config;

public:
    static void setEngine(Engine* engine) {
        e = engine;
        ago = e->getAGO();
        window = e->getGameWindow();
        config = e->getConfig();
    }

    static void createPlayer() {
        // create player instance
        auto* player = new GameObject("Player");
        ago->add(player);
        e->setPlayer(player);

        // create position component
        auto* position = new Position(player);
        player->addPosition(position);

        // renderer
        auto* pRenderer = new SpriteRenderer(player, window);
        pRenderer->setSprite("sprites/player/player_down.svg");
        pRenderer->setSize({16,16});
        player->addComponent(pRenderer);

        // attack renderer
        auto* aRenderer = new SpriteRenderer(player, window);
        aRenderer->setSprite("sprites/empty.svg");
        aRenderer->setSize({16, 16});
        player->addComponent(aRenderer);

        // changeSpriteOnMove
        auto* spriteChanger = new ChangeSpriteOnMove(player, pRenderer);
        spriteChanger->setDownSprite("sprites/player/player_down.svg");
        spriteChanger->setLeftSprite("sprites/player/player_left.svg");
        spriteChanger->setRightSprite("sprites/player/player_right.svg");
        spriteChanger->setUpSprite("sprites/player/player_up.svg");
        player->addComponent(spriteChanger);

        // attack animator
        auto* attackAnimator = new AttackAnimator(player, pRenderer, aRenderer);
        attackAnimator->setPlayerAttackSprites(
                "sprites/player/player_up_attacking.svg",
                "sprites/player/player_down_attacking.svg",
                "sprites/player/player_left_attacking.svg",
                "sprites/player/player_right_attacking.svg");
        attackAnimator->setAttackSprites(
                "sprites/player/sword_attack1.svg",
                "sprites/player/sword_attack2.svg",
                "sprites/player/sword_attack3.svg");
        attackAnimator->setAttackTime(.3);
        player->addComponent(attackAnimator);

        // movement
        auto* movement = new Movement(player);
        movement->setSpeed(config->playerSpeed);
        player->addComponent(movement);

        // player input
        auto* playerInputController = new PlayerInputController(player, window);
        player->addComponent(playerInputController);

        // player script
        auto* playerScript = new EntityScript(player, playerInputController, movement, attackAnimator);
        player->addComponent(playerScript);
    }


    static void createWall(int x, int y, const std::string& theme, bool wallSurroundings[3][3]) {
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


    static void createFloor(int x, int y, const std::string& theme) {
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


    static void createRoomLink(int x, int y, std::string targetLevel, std::string targetPoint) {
        auto* roomLink = new GameObject("RoomLink_" + std::to_string(x) + " " + std::to_string(y));
        ago->add(roomLink);

        auto* position = new Position(roomLink);
        position->moveTo(x,y);
        roomLink->addPosition(position);

        auto* playerCollider = new PlayerCollider(roomLink);
        roomLink->addComponent(playerCollider);

        auto* rlComp = new RoomLink(roomLink, playerCollider);
        rlComp->setTargetLevel(std::move(targetLevel));
        rlComp->setTargetPoint(std::move(targetPoint));
        roomLink->addComponent(rlComp);
    }


    static void createHolyDocumentation(int x, int y) {
        auto* holy = new GameObject("holy");
        ago->add(holy);

        auto* position = new Position(holy);
        position->moveTo(x, y);
        holy->addPosition(position);
        auto* renderer = new SpriteRenderer(holy, window);
        renderer->setSize({16,16});
        renderer->setSprite("sprites/HolyDoc.svg");
        holy->addComponent(renderer);
    }


    static void createCorridor(int x, int y, const std::string& theme) {
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


    static void createGhost(int x, int y) {
        GameObject *enemy = new GameObject("TestEnemy");
        ago->add(enemy);
        auto *position = new Position(enemy);
        position->moveTo(x, y);
        enemy->addPosition(position);
        auto *sr = new SpriteRenderer(enemy, window);
        sr->setSprite("sprites/enemies/ghost.png");
        sr->setSize({16, 16});
        sr->forceToFront();
        enemy->addComponent(sr);
        auto *pr = new PathRenderer(enemy, window);
        if(Engine::getInstance()->getConfig()->pathFinderPaths) {
            pr->setWidth(4);
            pr->forceToFront();
            pr->setColor(255, 60, 0);
            enemy->addComponent(pr);
        } else pr = nullptr;
        auto *m = new Movement(enemy);
        m->setSpeed(1.5);
        enemy->addComponent(m);
        auto *asc = new AStartController(enemy, pr);
        enemy->addComponent(asc);
        auto *ec = new EntityScript(enemy, asc, m, nullptr);
        enemy->addComponent(ec);
    }
};


#endif //ALGOVIZADVENTURE_PREFABS_HPP
