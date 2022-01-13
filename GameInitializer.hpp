// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
#define ALGOVIZADVENTURE_GAMEINITIALIZER_HPP

#include "ActiveGameObjects.hpp"

class GameInitializer {

    ActiveGameObjects ago;

    GameInitializer() {
        ago = ActiveGameObjects();
        windowCreation();
        setupControls();
        createPlayerInstance();
        startGameLoop();
    }

    void windowCreation() {

    }

    void setupControls() {

    }

    void createPlayerInstance() {

        // ago.add(playerInstance);
    }

    void startGameLoop() {

    }

};

#endif //ALGOVIZADVENTURE_GAMEINITIALIZER_HPP
