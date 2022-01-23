// Created by Lypoluz (Dominik) on 22.01.2022.

#ifndef ALGOVIZADVENTURE_ATTACKER_HPP
#define ALGOVIZADVENTURE_ATTACKER_HPP

#include "../engine/GameComponent.hpp"
#include "../engine/Engine.hpp"
#include "Health.hpp"

class Attacker : public GameComponent {

    Position* position;
    GTime* gTime;
    float timer;
    float attackCooldown = .5;
    Engine* e;
    ActiveGameObjects* ago;
    int damage = 10;


public:
    Attacker(ObjectStructure* os) : GameComponent(os) {
        timer = attackCooldown * 2;
    }

    void onStart() override {
        e = Engine::getInstance();
        gTime = e->getGTime();
        position = ((GameObject*) gameObject)->position;
    }

    void update() override {
        timer += gTime->deltaTime();
    }
    void setDamage(int d) {damage = d;}

    void attack() {
        if(timer < attackCooldown) return;

        std::vector<GameObject*> attackables = ago->getAttackables();

        // REFACTOR: into two classes
        if(gameObject->getName() == "Player") {
            for (GameObject * go : attackables) {
                if(go->getName() != "Player") {
                    if((position->getPosition() - go->position->getPosition()).magnitude() < 1.8) {
                        go->getComponent("Health");
                    }
                }
            }
        } else {
            if ((((GameObject*) e->getPlayer())->position->getPosition() - position->getPosition()).magnitude() < 1) {
                ((Health*)e->getPlayer()->getComponent("Health"))->reduceHealth(damage);
            }
        }

        timer = 0;
    }

    void setAttackCooldown(float coolDown) { attackCooldown = coolDown;}
};

#endif //ALGOVIZADVENTURE_ATTACKER_HPP
