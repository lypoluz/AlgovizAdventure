// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_CREATEENEMYEXAMPLE_HPP
#define ALGOVIZADVENTURE_CREATEENEMYEXAMPLE_HPP

#include "GameObject.hpp"
#include "ActiveGameObjects.hpp"

void myFunction(ActiveGameObjects& ago) {

    /*
     * Dieser Code soll zeigen, wie ein neues GameObject, hier ein Gegner, erstellt werden kann.
     * Eine solche Implementation kann zum Beispiel beim LevelBuilder verwendet werden.
     */

    /*
     * Zuerst muss das GameObject erstellt werden. Der Konstruktor nimmt einen string, welchen den Namen des
     * Objektes repräsentiert.
     * Anschließend muss 'myEnemy' der 'ActiveGameObject' Klasse übergeben werden. Andernfalls existiert das Objekt
     * nicht in der Szene.
     */
    GameObject myEnemy("myEnemy");
    ago.add(&myEnemy);

    /*
     * Die 'Position'-Komponente wird von jedem 'GameObject' benötigt und muss mit der speziellen Funktion
     * 'addPosition' übergeben werden.
     */
    Position positionComponent = Position();
    myEnemy.addPosition(&positionComponent);







};



#endif //ALGOVIZADVENTURE_CREATEENEMYEXAMPLE_HPP
