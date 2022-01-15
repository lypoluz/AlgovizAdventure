// Created by Lypoluz (Dominik) on 15.01.2022.

#ifndef ALGOVIZADVENTURE_CIRCLERENDERER_HPP
#define ALGOVIZADVENTURE_CIRCLERENDERER_HPP

#include "Renderer.hpp"

class CircleRenderer : public Renderer {

    AlgoWrapper::CircleShape circle;

public:
    CircleRenderer(ObjectStructure* os, AlgoWrapper::Window* win) : Renderer(os, win) {
        circle = AlgoWrapper::CircleShape(Vector2::zero(), 1, window);
        element = circle;
    }

    void setRadius(int r) {circle.setRadius(r);}
    void setFill(int r, int g, int b, float a=1) {circle.setFill(r,g,b,a);}
    void setColor(int r, int g, int b, float a=1) {circle.setColor(r,g,b,a);}
    void setStrokeWidth(int width) {circle.setStrokeWidth(width);}


};


#endif //ALGOVIZADVENTURE_CIRCLERENDERER_HPP
