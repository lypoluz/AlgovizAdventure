//
// Created by tobia on 12.01.2022.
//
#include <string>

class Roomlink{
    std::string name;
    std::string target;
    int posX;
    int posY;

public:

    Roomlink(std::string name, std::string target, int posX, int posY){
        this->name = name;
        this->target = target;
        this->posX = posX;
        this->posY = posY;
    }


    std::string getName(){
        return name;
    }

    std::string getTarget(){
        return target;
    }

    int getX(){
        return posX;
    }

    int getY(){
        return posY;
    }

};
