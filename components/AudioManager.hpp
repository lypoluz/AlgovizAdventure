// Created by Lypoluz (Dominik) on 23.01.2022.

#ifndef ALGOVIZADVENTURE_AUDIOMANAGER_HPP
#define ALGOVIZADVENTURE_AUDIOMANAGER_HPP

#include "../engine/GameComponent.hpp"
#include "../engine/Engine.hpp"
#include "../audioSystem/AudioPlayer.hpp"

class AudioManager : public GameComponent {
    bool alreadyPlayedStart = false;
    bool alreadyPlayed01= false;

public:
    AudioManager(ObjectStructure* os) : GameComponent(os) {}

    void onStart() override {
        std::string levelName = Engine::getInstance()->getCurrentLevel().name;
        Logger::logln("[AM] playing sound of " + levelName);
        if(levelName == "start.level" && !alreadyPlayedStart) {
            AudioPlayer::play("start.mp3");
            alreadyPlayedStart = true;
        }else if (levelName == "01.level" && !alreadyPlayed01){
            AudioPlayer::play("01.mp3");
            alreadyPlayed01 = true;
        }
    }

};

#endif //ALGOVIZADVENTURE_AUDIOMANAGER_HPP
