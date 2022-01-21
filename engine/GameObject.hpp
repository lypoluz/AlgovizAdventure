// Created by dominik on 12.01.2022.

#ifndef ALGOVIZADVENTURE_GAMEOBJECT_HPP
#define ALGOVIZADVENTURE_GAMEOBJECT_HPP

#include <string>
#include <utility>
#include <vector>
#include "../components/Position.hpp"
#include "ObjectStructure.hpp"
#include "../utils.cpp"

int lastGoId = 0;

class GameObject : public ObjectStructure {
    std::vector<ObjectStructure *> components;
    std::string name{};

    int id;

public:
    Position* position{}; // required component


    explicit GameObject(std::string name) {
        this->name = std::move(name);
        id = lastGoId;
        lastGoId++;
    }


    std::string getName() override {return name;}
    int getId() const {return id;}


    void addComponent(ObjectStructure* component) override {
        components.push_back(component);
    }

    void addPosition(Position * posComp) {
        position = posComp;
        addComponent((ObjectStructure*) posComp);
    }

    ObjectStructure* getComponent(std::string name) override {
        for (ObjectStructure* component : components)
            if (component->getName() == name)
                return component;
        return nullptr;
    }


    void onStart() override {
        if(not position)
            runtimeError(stringBuilder({"GameObject", getName(), "has no 'Position' component"}));

        for (ObjectStructure* component : components)
            component->onStart();
    }
    void preUpdate() override {
        for (ObjectStructure* component : components)
            component->preUpdate();
    }
    void update() override {
        for (ObjectStructure* component : components)
            component->update();
    }
    void postUpdate() override {
        for (ObjectStructure* component : components)
            component->postUpdate();
    }
    void onDestroy() override {
        for (ObjectStructure* component : components)
            component->onDestroy();
    }

};

#endif