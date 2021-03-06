// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_CREATETESTCOMPONENT_HPP
#define ALGOVIZADVENTURE_CREATETESTCOMPONENT_HPP

#include <iostream>
#include "engine/GameComponent.hpp"

class CreateTestComponent : public GameComponent {

public:
    /*
     * Ein Konstruktor ist wie hier notwendig. Dieser ruft einfach den Konstruktor der Basisklasse auf.
     * Der Codeblock des Konstruktors kann leer bleiben.
     */
    explicit CreateTestComponent(ObjectStructure* os) : GameComponent(os) {}


    // 'getName' sollte sen Namen der Klasse zurückgeben. Diese Funktion muss definiert werden.
    std::string getName() override {return "CreateTestComponent";}


    // 'onStart', wird aufgerufen, sobald eine Instanz von der Komponente erstellt wird und in dem Spiel zu sehen ist.
    void onStart() override {
        std::cout << "Ich erwache!" << std::endl;
    }


    // 'update', wird in jedem Frame aufgerufen. Das sollte normalerweise verwendet werden.
    void update() override {
        std::cout << "Update!" << std::endl;
    }


    // 'postUpdate', wird auch in jedem Frame aufgerufen, aber erst, nachdem update in jeder Komponente aufgerufen wurde.
    void postUpdate() override {
        std::cout << "PostUpdate!" << std::endl;
    }


    /*
     * 'onDestroy', wird aufgerufen, wenn diese Komponente aus der Szene genommen wird. Z.B. weil der Spieler das Level
     * verlässt, oder wenn der Spieler den Gegner besiegt.
     */
    void onDestroy() override {
        std::cout << "Ich wurde zerstört!" << std::endl;
    }


    /*
     * In CLion kann jede der Methoden, außer dem Konstruktor, durch die Tastenkombination STRG+O eingefügt werden, wenn
     * die Klasse von 'GameComponent' erbt.
     */
};

#endif //ALGOVIZADVENTURE_CREATETESTCOMPONENT_HPP
