// Created by Lypoluz (Dominik) on 19.01.2022.

#ifndef ALGOVIZADVENTURE_CREATE_HPP
#define ALGOVIZADVENTURE_CREATE_HPP

#include "engine/ActiveGameObjects.hpp"
#include "engine/Engine.hpp"
#include "WallComponent.hpp"
#include "SpriteRenderer.hpp"

void myFunction() {

    for (int i = 0; i < 10; ++i) {
        ActiveGameObjects* ago = Engine::getInstance()->getAGO();
        AlgoWrapper::Window* window = Engine::getInstance()->getGameWindow();

        GameObject* wall = new GameObject("wall" + i);
        ago->add(wall);

        int x, y;
        Position* position = new Position(wall);
        position->moveTo(x, y);
        wall->addPosition(position);

        WallComponent* wallComp = new WallComponent(wall);
        wall->addComponent(wallComp);

        auto* renderer = new SpriteRenderer(wall, window);
        renderer->setSprite("PathToPNG");
        renderer->setSize({16,16});
        wall->addComponent(renderer);

    }

}

#endif //ALGOVIZADVENTURE_CREATE_HPP
