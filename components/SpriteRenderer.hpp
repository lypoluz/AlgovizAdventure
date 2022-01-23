// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_SPRITERENDERER_HPP
#define ALGOVIZADVENTURE_SPRITERENDERER_HPP

#include "../engine/GameComponent.hpp"
#include "../AlgoWrapper.hpp"
#include "../engine/GameObject.hpp"
#include "abstract/Renderer.hpp"
#include "../Logger.hpp"

class SpriteRenderer : public Renderer {
    AlgoWrapper::Sprite sprite{};
    Vector2 dimension;
    std::string currentSprite;

public:
    SpriteRenderer(ObjectStructure* os, AlgoWrapper::Window* win) : Renderer(os, win) {
        dimension = Vector2::one();
        sprite = AlgoWrapper::Sprite("sprites/empty.svg", position->getPosition() * 16, dimension, window);
    }

    void setSprite(const std::string& pathToSprite) {
        currentSprite = pathToSprite;
        sprite.changeSprite(pathToSprite);
        element = &sprite;
    }

    void setSize(Vector2 d) {dimension = d; sprite.setSize(dimension);}

    std::string getSpritePath() {return currentSprite;}

    void onDestroy() override {
        setSprite("sprites/empty.svg");
    }
};

#endif //ALGOVIZADVENTURE_SPRITERENDERER_HPP
