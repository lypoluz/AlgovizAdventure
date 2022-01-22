// Created by Lypoluz (Dominik) on 22.01.2022.

#ifndef ALGOVIZADVENTURE_PATHRENDERER_HPP
#define ALGOVIZADVENTURE_PATHRENDERER_HPP

#include "abstract/Renderer.hpp"
#include "../AlgoWrapper.hpp"

#include <utility>

class PathRenderer : public Renderer {
    AlgoWrapper::svgPath svgpath{};
    std::string path{};

public:
    PathRenderer(ObjectStructure* os, AlgoWrapper::Window* win) : Renderer(os, win) {
        svgpath = AlgoWrapper::svgPath("", win);
        element = &svgpath;
        svgpath.setFill(0,0,0,0);
    }

    void setPath(std::string p) {
        path = std::move(p);
        Logger::logln("[PR] " + path);
        svgpath.setPath(path);
    }

    void setWidth(int width) {svgpath.setStrokeWidth(width);}
    void setColor(int r, int g, int b, float a=1) {svgpath.setColor(r,g,b,a);}
};

#endif //ALGOVIZADVENTURE_PATHRENDERER_HPP
