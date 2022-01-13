// created by dominik

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

