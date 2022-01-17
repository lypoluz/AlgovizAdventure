// Created by Lypoluz (Dominik) on 14.01.2022.

#ifndef ALGOVIZADVENTURE_SPRITERENDERER_HPP
#define ALGOVIZADVENTURE_SPRITERENDERER_HPP

#include "engine/GameComponent.hpp"
#include "../AlgoWrapper.hpp"
#include "engine/GameObject.hpp"
#include "abstract/Renderer.hpp"

class SpriteRenderer : public Renderer {
    AlgoWrapper::Sprite sprite;

public:
    SpriteRenderer(ObjectStructure* os, AlgoWrapper::Window* win) : Renderer(os, win) {}

    void setSprite(const std::string& pathToSprite, Vector2 dim=Vector2::one()) {
        sprite = AlgoWrapper::Sprite(pathToSprite, position->getPosition(), dim, window);
        element = &sprite;
    }

    void setSize(Vector2 dimension) {sprite.setSize(dimension);}
};

#endif //ALGOVIZADVENTURE_SPRITERENDERER_HPP
