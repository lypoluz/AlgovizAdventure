//
// Created by dominik on 12.01.2022.
//

#ifndef ALGOVIZADVENTURE_GAMECOMPONENT_H
#define ALGOVIZADVENTURE_GAMECOMPONENT_H


#include <string>

class GameComponent {

    std::string name;
    virtual void OnStart() {};
    virtual void OnUpdate(){};
};


#endif //ALGOVIZADVENTURE_GAMECOMPONENT_H
