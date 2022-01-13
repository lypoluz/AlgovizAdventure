// created by dominik

#ifndef ALGOVIZADVENTURE_GAMECOMPONENT_HPP
#define ALGOVIZADVENTURE_GAMECOMPONENT_HPP

class GameObject;

class GameComponent {


protected:
    GameObject* gameObject{};

public:
    void setGameObject(GameObject* gameObj) {
        gameObject = gameObj;
    }
    GameObject* getGameObject() {return gameObject;}

    virtual void onStart() {}
    virtual void preUpdate() {} // shouldn't be used
    virtual void update() {}
    virtual void postUpdate() {}

};

#endif