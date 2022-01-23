// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_UI_HPP
#define ALGOVIZADVENTURE_UI_HPP

#include "../engine/GameComponent.hpp"
#include "SpriteRenderer.hpp"
#include "../engine/Engine.hpp"

class UI : public GameComponent {

    SpriteRenderer* spriteRenderer[4]{};
    SpriteRenderer* holyRenderer{};
    AlgoWrapper::Window* window;


public:
    UI (ObjectStructure* os) : GameComponent(os) {
        int wfsf = Engine::getInstance()->getConfig()->windowFrameSizeFactor;
        window = new AlgoWrapper::Window(112, 480, wfsf, wfsf, "UI");
    }

    void setLifeRenderer(SpriteRenderer* sr, int i) {
        spriteRenderer[i] = sr;
    }

    void setHolyRender(SpriteRenderer* hd) {
        holyRenderer = hd;
    }
    void setLives(int l) {
        for (int i = 0; i < 4; ++i) {
            if (l > i) spriteRenderer[i]->show();
            else spriteRenderer[i]->hide();
        }
    }

    void setHoly() {
        holyRenderer->show();
    }

    AlgoWrapper::Window* getWindow() {return window;}


};

#endif //ALGOVIZADVENTURE_UI_HPP
