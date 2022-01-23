// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_PREFABS_HPP
#define ALGOVIZADVENTURE_PREFABS_HPP

#include "engine/Engine.hpp"
#include "components/SpriteRenderer.hpp"
#include "components/ChangeSpriteOnMove.hpp"
#include "components/AttackAnimator.hpp"
#include "components/Movement.hpp"
#include "components/PlayerInputController.hpp"
#include "components/EntityScript.hpp"
#include "components/WallComponent.hpp"
#include "components/PlayerCollider.hpp"
#include "components/RoomLink.hpp"
#include "components/PathRenderer.hpp"
#include "components/AStarController.hpp"
#include "components/HolyDoc.hpp"
#include "components/AudioManager.hpp"

class Prefabs {
    Engine* e;
    ActiveGameObjects* ago;
    AlgoWrapper::Window* window;
    Config* config;

public:
    static Prefabs& create() {
        static Prefabs instance;
        return instance;
    }

    void setEngine(Engine* engine) {
        e = engine;
        ago = e->getAGO();
        window = e->getGameWindow();
        config = e->getConfig();
    }

    void player() {
        e->reloadLevel(false);
        // create player instance
        auto* player = new GameObject("Player");
        ago->addAttackable(player);
        e->setPlayer(player);

        // create position component
        auto* position = new Position(player);
        player->addPosition(position);

        // renderer
        auto* pRenderer = new SpriteRenderer(player, window);
        pRenderer->setSprite("sprites/player/player_down.svg");
        pRenderer->setSize({16,16});
        player->addComponent(pRenderer);
        e->addOnTopRenderer((ObjectStructure*)pRenderer);

        // attack renderer
        auto* aRenderer = new SpriteRenderer(player, window);
        aRenderer->setSprite("sprites/empty.svg");
        aRenderer->setSize({16, 16});
        player->addComponent(aRenderer);
        e->addOnTopRenderer((ObjectStructure*)aRenderer);

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

        auto* attacker = new Attacker(player);
        attacker->setDamage(20);
        player->addComponent(attacker);

        auto* health = new Health(player);
        health->setHealth(30);
        player->addComponent(health);

        // movement
        auto* movement = new Movement(player);
        movement->setSpeed(config->playerSpeed);
        player->addComponent(movement);

        // player input
        auto* playerInputController = new PlayerInputController(player, window);
        player->addComponent(playerInputController);

        // player script
        auto* playerScript = new EntityScript(player, playerInputController, movement, attackAnimator, attacker);
        player->addComponent(playerScript);
    }


    void wall(int x, int y, const std::string& theme, bool wallSurroundings[3][3]) {
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


    void floor(int x, int y, const std::string& theme) {
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


    void roomLink(int x, int y, std::string targetLevel, std::string targetPoint) {
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


    void holyDocumentation(int x, int y) {
        auto* hd = new GameObject("hd");
        ago->add(hd);

        auto* position = new Position(hd);
        position->moveTo(x, y);
        hd->addPosition(position);

        auto* renderer = new SpriteRenderer(hd, window);
        renderer->setSize({16,16});
        renderer->setSprite("sprites/HolyDoc.svg");
        hd->addComponent(renderer);
        e->addOnTopRenderer((ObjectStructure*) renderer);

        auto* collider = new PlayerCollider(hd);
        hd->addComponent(collider);

        auto* hdc = new HolyDoc(hd, collider);
        hd->addComponent(hdc);
    }


    void corridor(int x, int y, const std::string& theme) {
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


    void ghost(int x, int y) {
        GameObject *enemy = new GameObject("TestEnemy");
        ago->addAttackable(enemy);

        auto *position = new Position(enemy);
        position->moveTo(x, y);
        enemy->addPosition(position);

        auto *sr = new SpriteRenderer(enemy, window);
        sr->setSprite("sprites/enemies/ghost.svg");
        sr->setSize({16, 16});
        sr->forceToFront();
        enemy->addComponent(sr);
        e->addOnTopRenderer((ObjectStructure*) sr);

        auto *pr = new PathRenderer(enemy, window);
        if(Engine::getInstance()->getConfig()->pathFinderPaths) {
            pr->setWidth(4);
            pr->forceToFront();
            pr->setColor(255, 60, 0);
            enemy->addComponent(pr);
            e->addOnTopRenderer((ObjectStructure*) pr);
        } else pr = nullptr;

        auto *m = new Movement(enemy);
        m->setSpeed(1.5);
        enemy->addComponent(m);

        auto *asc = new AStarController(enemy, pr);
        enemy->addComponent(asc);

        auto* attacker = new Attacker(enemy);
        attacker->setAttackCooldown(1);
        attacker->setDamage(10);
        enemy->addComponent(attacker);

        auto* health = new Health(enemy);
        health->setHealth(15);
        enemy->addComponent(health);

        auto *ec = new EntityScript(enemy, asc, m, nullptr, attacker);
        enemy->addComponent(ec);
    }

    void blocker(int x, int y){
        auto* blocker = new GameObject("blocker" + std::to_string(x) + std::to_string(y));
        ago->add(blocker);

        //instantiate position component
        auto* position = new Position(blocker);

        //set position to value
        position->moveTo(x, y);

        //game object gets its position
        blocker->addPosition(position);

        auto* blockerComp = new WallComponent(blocker);
        blocker->addComponent(blockerComp);

        auto* renderer = new SpriteRenderer(blocker, window);
        renderer->setSize({16,16});
        renderer->setSprite("sprites/default/blocker.svg");
        blocker->addComponent(renderer);
    }


     void audioManager() {
        auto* am = new GameObject("AudioManager");
        ago->addPersistent(am);

        auto* pos = new Position(am);
        am->addPosition(pos);

        auto* amc = new AudioManager(am);
        am->addComponent(amc);
    }


    void ui() {
        auto* ui = new GameObject("UI");
        ago->addPersistent(ui);

        auto* pos = new Position(ui);
        ui->addPosition(pos);

        auto* uic = new UI(ui);
        ui->addComponent(uic);
        AlgoWrapper::Window* uiWindow = uic->getWindow();
        e->setUI(uic);

        auto* back = new SpriteRenderer(ui, uiWindow);
        back->setSprite("sprites/uiBack.svg");
        back->setSize({112, 480});
        back->setPositionOffset({3, 14.5});
        ui->addComponent(back);

        auto* sr1 = new SpriteRenderer(ui, uiWindow);
        sr1->setSprite("sprites/player/player_down.svg");
        sr1->setSize({16, 16});
        sr1->setPositionOffset({3.6,2.8});
        ui->addComponent(sr1);
        uic->setLifeRenderer(sr1, 0);

        auto* sr2 = new SpriteRenderer(ui, uiWindow);
        sr2->setSprite("sprites/player/player_down.svg");
        sr2->setSize({16, 16});
        sr2->setPositionOffset({4.8,2.7});
        ui->addComponent(sr2);
        uic->setLifeRenderer(sr2, 1);

        auto* sr3 = new SpriteRenderer(ui, uiWindow);
        sr3->setSprite("sprites/player/player_down.svg");
        sr3->setSize({16, 16});
        sr3->setPositionOffset({5.5,1.7});
        ui->addComponent(sr3);
        uic->setLifeRenderer(sr3, 2);

        auto* sr4 = new SpriteRenderer(ui, uiWindow);
        sr4->setSprite("sprites/player/player_down.svg");
        sr4->setSize({16, 16});
        sr4->setPositionOffset({5.7,0.4});
        ui->addComponent(sr4);
        uic->setLifeRenderer(sr4, 3);

        auto* hd = new SpriteRenderer(ui, uiWindow);
        hd->setSprite("sprites/HolyDoc.svg");
        hd->setSize({32,32});
        hd->setPositionOffset({0.5,.8});
        hd->hide();
        ui->addComponent(hd);
        uic->setHolyRender(hd);


    }
};


#endif //ALGOVIZADVENTURE_PREFABS_HPP
