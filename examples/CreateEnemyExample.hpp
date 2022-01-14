// Created by Lypoluz (Dominik) on 13.01.2022.

#ifndef ALGOVIZADVENTURE_CREATEENEMYEXAMPLE_HPP
#define ALGOVIZADVENTURE_CREATEENEMYEXAMPLE_HPP

#include "GameObject.hpp"
#include "ActiveGameObjects.hpp"
#include "CreateTestComponent.hpp"

void myFunction(ActiveGameObjects& ago) {

    /*
     * Dieser Code soll zeigen, wie ein neues GameObject, hier ein Gegner, erstellt werden kann.
     * Eine solche Implementation kann zum Beispiel beim LevelBuilder verwendet werden.
     * Soll ein neuer Gegner erstellt werden. So wird bloß eine neue Instanz von 'GameObject' erstellt. Es soll nicht
     * eine neue Klasse geschrieben werden, welche von 'GameObject' erbt. Jede Funktionalität / jedes Feature wird in
     * Klassen definiert, die von 'GameComponent' erben. Diese Funktionalität kann dann einem 'GameObject' zugeschrieben
     * werden. (Diese Form von Zuschreibung nennt man auch 'Dependency injection').
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
    Position positionComponent = Position(&myEnemy);
    myEnemy.addPosition(&positionComponent);

    /*
     * Jetzt können wir unsere Beispiel-Komponente 'CreateTestComponent' hinzufügen. Jede Komponente, die ein
     * GameObject besitzen soll, muss mit 'addComponent hinzugefügt werden'
     */
    CreateTestComponent testComp = CreateTestComponent(&myEnemy);
    myEnemy.addComponent((ObjectStructure*)&testComp);






};



#endif //ALGOVIZADVENTURE_CREATEENEMYEXAMPLE_HPP
