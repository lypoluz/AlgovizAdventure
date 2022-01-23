// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_UI_HPP
#define ALGOVIZADVENTURE_UI_HPP

#include "../engine/GameComponent.hpp"
#include "SpriteRenderer.hpp"
#include "Engine.hpp"

class UI : public GameComponent {

    SpriteRenderer* spriteRenderer[4]{};
    SpriteRenderer* holyRenderer{};
    AlgoWrapper::Window window;


public:
    UI (ObjectStructure* os) : GameComponent(os) {}

    void setLifeRenderer(SpriteRenderer* sr[4]) {
        for (auto & i : spriteRenderer)
            i = sr[4];
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

    void createNewWindow() {
        int wfsf = Engine::getInstance()->getConfig()->windowFrameSizeFactor;
        window = AlgoWrapper::Window(112, 480, wfsf, wfsf, "UI");
    }

    AlgoWrapper::Window* getWindow() {return &window;}


};

#endif //ALGOVIZADVENTURE_UI_HPP
