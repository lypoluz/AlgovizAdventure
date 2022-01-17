#ObjectStructure-Klassen
##GameComponent
Diese Variablen und Funktionen sind nur innerhalb von GameComponent verfügbar.

###Variablen
`std::string name`  
Name der Komponente, wenn eine gesetzt ist.

`ObjectStructure* gameObject`  
Eine Referenz zu dem GameObject, zu welchem diese Instanz der gehört. Da der DatenTyp ObjectStructure* ist, muss gegebenenfalls gecastet werden `(GameObject*) gameObject`.
 
###Funktionen
`void addComponent(ObjectStructure * component)`  
Fügt dem GameObject, zu welchem diese Instanz der Komponente gehört, eine neue Komponente `component` hinzu.

`ObjectStructure* getComponent(std::string name)`  
Gibt eine Referenz zu der Komponente des GameObjects zurück mit dem Namen `name`. Die Referenz muss gegebenenfalls gecastet werden. Existiert keine solche Komponente, wird ein `nullptr` zurückgegeben.

###Funktionen zum Implementieren
`void onStart() override`  
wird aufgerufen, wenn das Spiel startet, bzw. ein neues Level geladen wird.

`void update() override`  
wird in jedem Frame aufgerufen.

`void postUpdate() override`  
wird ebenfalls in jedem Frame aufgerufen, aber garantiert nachdem, in jeder Komponente `update()` aufgerufen wurde.

`void onDestroy() override`  
wird aufgerufen, sobald das dazugehörige GameObject aus der Szene genommen wird. Z.B. wenn das Level entladen wird, oder weil der Spieler dieses GameObject / diesen Gegner besiegt hat.

---
##GameObject
###Variablen
`Position* position`  
ist ein Pointer auf die Position-Komponente des GameObjects.

###Funktionen
`void addComponent(ObjectStructure * component)`  
Fügt dem GameObject, eine neue Komponente `component` hinzu.

`ObjectStructure* getComponent(std::string name)`  
Gibt eine Referenz zu der Komponente des GameObjects zurück mit dem Namen `name`. Die Referenz muss gegebenenfalls gecastet werden. Existiert keine solche Komponente, wird ein `nullptr` zurückgegeben.

`std::string getName()`  
gibt den Namen des GameObjects aus.

---
---
#Engine-Klassen
##Engine
`Engine* getInstance()`  
return eine einmalige Engine Instanz welche eine Referenz zu allen Engine-Klasse besitzt, sowie dem GameObject des Spielers.

`ObjectStructure* getPlayer()`  
gibt den Pointer zur GameObject Instanz des Spielers aus. Muss gegebenenfalls gecastet werden.

`GTime* getGTime()`  
gibt den Pointer zur GTime Instanz aus.

---
##GTime
`double deltaTime()`  
gibt die Dauer des letzten Frames in Sekunden aus.

`double runTime()`
gibt die Dauer des Programs aus, seitdem die GameLoop startete.
