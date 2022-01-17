#Utils
##utils.cpp

`float randonFloat(float min=0, float max=1)`  
gibt einen zufälligen Wert als Gleitkommazahl zwischen `min` und `max` aus. Die Parameter sind optional, werden keine angegeben, so wird eine zufällige Gleitkommazahl zwischen 0 und 1 ausgegeben.

`void runtimeError(std::string errmsg)`  
wirft einen RuntimeError mit der Fehlernachricht `errmsg`.

---
---
#Datentypen
##Vector2
Die Klasse repräsentiert einen Vector mit 2 Attributen, `x` und `y`.
###Konstruktoren
`Vector2()`  
erstellt einen Vector2 mit `x=0` und `y=0`.

`Vector2(float x, float y)`  
erstellt einen Vector2 mit den Werten `x` und `y`.

###Statics
`Vector2::zero()`  
erstellt einen Vector2 mit `x=0` und `y=0`.

`Vector2::one()`  
erstellt einen Vector2 mit `x=1` und `y=1`.

`Vector2::up()`  
erstellt einen Vector2 mit `x=0` und `y=-1`.

`Vector2::down)`  
erstellt einen Vector2 mit `x=0` und `y=1`.

`Vector2::left()`  
erstellt einen Vector2 mit `x=-1` und `y=0`.

`Vector2::right()`  
erstellt einen Vector2 mit `x=1` und `y=0`.

`Vector2::random(float min=0, float max=1)`  
erstellt einen Vector2 mit zufälligen Werten für `x` und `y` zwischen `min` und `max`. Die Parameter sind optional, werden keine angegeben, so werden zufällige Gleitkommazahlen zwischen 0 und 1 gewählt.

###Funktionen

`float x()`  
gibt den x-Wert des Vektors aus.

`float y()`  
gibt den y-Wert des Vektors aus.

`void x(flaot x)`  
setzt den x-Wert des Vektors.

`void y(flaot y)`  
setzt den y-Wert des Vektors.

`void set(float x, float y)`  
überschreibt `x` und `y` mit den Werten der Parameter.

`Vector2 normalized()`  
gibt einen neuen Vector2 zurück, welcher in die gleiche Richtung zeigt, aber eine Länge von 1 besitzt.

`float magnitude()`  
gibt die geometrische Länge des Vektors aus.

`float dotProd(Vector2 other)`  
berechnet das Skalarprodukt des Vektors mit other und gibt es aus.

`std::string toString()`  
gibt den Vector als formatierten, lesbaren String aus.

###Operatoren
####Vector2 mit Vector2
`<`, `<=`, `>`, `>=`  
vergleicht die Längen zweier Vektoren.

`==`, `!=`   
vergleicht zwei Vektoren auf Gleichheit. `x1==x2 && y1==y2`.

`+`, `+=`, `-`, `-=`, `*`, `*=`, `/`, `/=`  
verrechnet jeweils `x` und `y` unabhängig voneinander zweier Vektoren.

####Vector2 mit float
`*`, `*=`, `/`, `/=`  
verrechnet jeweils `x` und `y` unabhängig voneinander mit der Gleitkommazahl.