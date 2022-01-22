#ifndef ALGOVIZADVENTURE_UTILS_CPP
#define ALGOVIZADVENTURE_UTILS_CPP


#include <cstdlib>
#include <vector>
#include <string>
#include <stdexcept>
#include "Vector2.hpp"

float randomFloat(float min=0, float max=1) {
    return (float) std::rand() / RAND_MAX * std::abs(min - max) + min;
}

std::string stringBuilder(const std::vector<std::string>& strs) {
    std::string str;
    for (const std::string &s: strs)
        str.append(s).append(" ");
    return str;
}

void runtimeError(const std::string& errmsg) {
    throw std::runtime_error(errmsg);
}

std::string SVGPathFromVector2Vector(std::vector<Vector2> vects, float scale=1) {
    std::string path = "M " + std::to_string((int)(vects[0].x()*scale)) + " " + std::to_string((int)(vects[0].y()*scale));
    for(auto vec : vects)
        path += " L " + std::to_string((int)(vec.x()*scale)) + " " + std::to_string((int)(vec.y()*scale));
    return path;
}

#endif // ALGOVIZADVENTURE_UTILS_CPP