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
        if(levelName == "start.level") {
            AudioPlayer::play("start.mp3");
        }else if (levelName == "01.level"){
            AudioPlayer::play("01.mp3");
        }
    }

};

#endif //ALGOVIZADVENTURE_AUDIOMANAGER_HPP
