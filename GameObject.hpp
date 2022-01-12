// Created by dominik on 12.01.2022.


#include <string>
#include <vector>
#include "GameComponent.hpp"


class GameObject {
protected:
    std::vector<GameComponent*> components;

public:
    GameComponent* position;


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
    void update() {
        for (GameComponent* component : components)
            component->update();
    }
};
