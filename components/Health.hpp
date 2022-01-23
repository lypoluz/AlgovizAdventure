// Created by annika on 15.01.2022.

#ifndef ALGOVIZADVENTURE_HEALTH_HPP
#define ALGOVIZADVENTURE_HEALTH_HPP



#include "../engine/GameComponent.hpp"
#include "../engine/Engine.hpp"
#include "UI.hpp"


class Health : public GameComponent {

    int health;

public:
    explicit Health(ObjectStructure* os) : GameComponent(os) {}

    std::string getName() override {return "Health";}

    void onStart() override {
        updateUI();
    }


    void setHealth(int newHealth) {
        updateUI();
        health = newHealth;
        if (health <= 0) {
            if(gameObject -> getName() == "Player") {
                if(Engine::getInstance()->getCurrentLevel().name == "end.level"){
                    AlgoWrapper::exitFullscreen();
                    AlgoWrapper::compress();
                }else{
                    Engine::getInstance()->reloadLevel();
                }
            }
            else{
                Engine::getInstance()->getAGO()->remove((GameObject*) gameObject);
            }
        }
    }

    void updateUI() {
        if(gameObject -> getName() == "Player")
            ((UI*)Engine::getInstance()->getUI())->setLives(health/4);
    }

    void reduceHealth(int h) {
        if (health < 40) {
            setHealth(health - h);
        }
    }

};

#endif //ALGOVIZADVENTURE_HEALTH_HPP