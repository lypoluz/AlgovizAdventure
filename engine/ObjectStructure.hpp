// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_OBJECTSTRUCTURE_HPP
#define ALGOVIZADVENTURE_OBJECTSTRUCTURE_HPP

#include <string>


class ObjectStructure {
protected:
    std::string name;
public:
    virtual void addComponent(ObjectStructure*) = 0;
    virtual ObjectStructure* getComponent(std::string) = 0;
    virtual std::string getName() = 0;

    virtual void onStart() = 0;
    virtual void preUpdate() = 0; // shouldn't be used
    virtual void update() = 0;
    virtual void postUpdate() = 0;
    virtual void onDestroy() = 0;
};

#endif //ALGOVIZADVENTURE_OBJECTSTRUCTURE_HPP
