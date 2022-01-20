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
    SpriteRenderer(ObjectStructure* os, AlgoWrapper::Window* win) : Renderer(os, win) {dimension = Vector2::one(); }

    void setSprite(const std::string& pathToSprite) {
        currentSprite = pathToSprite;
        sprite = AlgoWrapper::Sprite(pathToSprite, position->getPosition() * 16, dimension, window);
        sprite.setAttribute("image-rendering", "crisp-edges");
        sprite.setAttribute("shape-rendering", "crispEdges");
        element = &sprite;
    }

    void setSize(Vector2 d) {dimension = d; sprite.setSize(dimension);}

    std::string getSpritePath() {return currentSprite;}
};

#endif //ALGOVIZADVENTURE_SPRITERENDERER_HPP
