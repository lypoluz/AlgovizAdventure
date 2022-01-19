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

public:
    SpriteRenderer(ObjectStructure* os, AlgoWrapper::Window* win) : Renderer(os, win) {dimension = Vector2::one(); }

    void setSprite(const std::string& pathToSprite) {
        sprite = AlgoWrapper::Sprite(pathToSprite, position->getPosition(), dimension, window);
        sprite.setAttribute("image-rendering", "crisp-edges");
        element = &sprite;
    }

    void setSize(Vector2 d) {dimension = d; sprite.setSize(dimension);}
};

#endif //ALGOVIZADVENTURE_SPRITERENDERER_HPP
