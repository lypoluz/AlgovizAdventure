#ifndef ALGOVIZADVENTURE_UTILS_CPP
#define ALGOVIZADVENTURE_UTILS_CPP


#include <cstdlib>
#include <vector>
#include <string>
#include <stdexcept>

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

#endif // ALGOVIZADVENTURE_UTILS_CPP