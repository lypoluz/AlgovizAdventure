// created by dominik

#ifndef ALGOVIZADVENTURE_GAMECOMPONENT_HPP
#define ALGOVIZADVENTURE_GAMECOMPONENT_HPP

#include "ObjectStructure.hpp"
#include "GTime.hpp"
//#include "Engine.hpp"

class GameComponent : public ObjectStructure {
protected:
    ObjectStructure* gameObject{};
    //GTime* gTime;

public:
    explicit GameComponent(ObjectStructure* gameObj) {
        gameObject = gameObj;
        name = typeid(*this).name();
        //gTime = Engine::getInstance()->getGTime();
    }
    ObjectStructure* getGameObject() {return gameObject;}

    void addComponent(ObjectStructure* component) override {gameObject->addComponent(component);}
    ObjectStructure* getComponent(std::string name) override {return gameObject->getComponent(name);}
    virtual std::string getName() override {return name;}

    virtual void onStart() override {}
    virtual void preUpdate() override {} // shouldn't be used
    virtual void update() override {}
    virtual void postUpdate() override {}
    virtual void onDestroy() override {}


};

#endif