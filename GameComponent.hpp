// created by dominik

#ifndef ALGOVIZADVENTURE_GAMECOMPONENT_HPP
#define ALGOVIZADVENTURE_GAMECOMPONENT_HPP

#include "ObjectStructure.hpp"

class GameComponent : public ObjectStructure {
protected:
    ObjectStructure* gameObject{};

public:
    explicit GameComponent(ObjectStructure* gameObj) {gameObject = gameObj; name = typeid(*this).name();}
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