// Created by dominik on 12.01.2022.


#include <string>
#include <utility>
#include <vector>
#include "GameComponent.hpp"
#include "components/Position.hpp"
#include "ActiveGameObjects.hpp"


class GameObject {
protected:
    std::vector<GameComponent*> components;

public:
    Position* position; // required component

    GameObject(ActiveGameObjects& ago, Position* posComp, std::vector<GameComponent *> comps=std::vector<GameComponent*>{}) {
        ago.add(this);
        position = posComp;
        components = std::move(comps);
        addComponent(*position);
    }


    template <typename T>
    T* getComponent() {
        for (GameComponent* component : components)
            if (dynamic_cast<T>(*component))
                return (T*) component;
        return nullptr;
    }

    void addComponent(GameComponent& component) {
        components.push_back(&component);
        component.setGameObject(this);
    }

    void onStart() {
        for (GameComponent* component : components)
            component->onStart();
    }
    void preUpdate() {
        for (GameComponent* component : components)
            component->preUpdate();
    }
    void update() {
        for (GameComponent* component : components)
            component->update();
    }
    void postUpdate() {
        for (GameComponent* component : components)
            component->postUpdate();
    }

};
