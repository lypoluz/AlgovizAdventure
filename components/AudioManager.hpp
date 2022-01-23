// Created by Tobias on 23.01.2022.

#ifndef ALGOVIZADVENTURE_AUDIOMANAGER_HPP
#define ALGOVIZADVENTURE_AUDIOMANAGER_HPP

#include "../engine/GameComponent.hpp"
#include "../engine/Engine.hpp"
#include "../audioSystem/AudioPlayer.hpp"

class AudioManager : public GameComponent {
    bool alreadyPlayedStart = false;
    bool alreadyPlayed01= false;
    float audioLevel = 1;

public:
    AudioManager(ObjectStructure* os) : GameComponent(os) {}

    void onStart() override {
        audioLevel = Engine::getInstance()->getConfig()->audioLevel;
        std::string levelName = Engine::getInstance()->getCurrentLevel().name;
        Logger::logln("[AM] playing sound of " + levelName);
        if(levelName == "start.level" && !alreadyPlayedStart) {
            AudioPlayer::play("start.mp3", audioLevel);
            alreadyPlayedStart = true;
        }else if (levelName == "01.level" && !alreadyPlayed01){
            AudioPlayer::play("01.mp3", audioLevel);
            alreadyPlayed01 = true;
        }
    }

};

#endif //ALGOVIZADVENTURE_AUDIOMANAGER_HPP
