// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_AUDIOMANAGER_HPP
#define ALGOVIZADVENTURE_AUDIOMANAGER_HPP

#include "../engine/GameComponent.hpp"
#include "Engine.hpp"
#include "AudioPlayer.hpp"

class AudioManager : public GameComponent {

public:
    AudioManager(ObjectStructure* os) : GameComponent(os) {}

    void onStart() override {
        std::string levelName = Engine::getInstance()->getCurrentLevel().name;
        if(levelName == "")
            AudioPlayer::play("audioName");
    }

};

#endif //ALGOVIZADVENTURE_AUDIOMANAGER_HPP
