// Created by Lypoluz (Dominik) on 20.01.2022.
// Easing functions from https://easings.net

#ifndef ALGOVIZADVENTURE_EASE_HPP
#define ALGOVIZADVENTURE_EASE_HPP

#include <cmath>

struct Ease {
    static float InOutQuart(float x) {return (x<.5)? 8*x*x*x*x : 1 - std::pow(-2*x+2, 4)/2;}
    static float InOutExpo(float x) {return (x<=0)? 0 : (x>=1)? 1 : (x<.5)? std::pow(2, 20*x-10)/2 : (2-std::pow(2, -20*x+10))/2;}
};

#endif //ALGOVIZADVENTURE_EASE_HPP
