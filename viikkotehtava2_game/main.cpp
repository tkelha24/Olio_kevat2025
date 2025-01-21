/*Toteuta alla olevan luokkakaavion mukainen luokka Game
Konstruktorissa parametrinä annetaan maksimiarvo, mille välille 1-maxNumber peli arpoo arvattavan luvun.
Play()-jäsenfunktioon toteutetaan peli.
printGameResult()-jäsenfunktiosta kutsutaan kun peli on päättynyt. Se tulostaa oikean vastauksen
ja kuinka monta arvausta siihen tarvittiin.
Luokan toteutuksessa täytyy olla molemmat otsikkotiedosto Game.h ja luokan toteutus Game.cpp
*/

#include <iostream>
#include "game.h"

int main() {
    int maxNumber;

    std::cout << "Anna suurin arvattava numero: ";
    std::cin >> maxNumber;

    Game game(maxNumber);

    game.play();

    return 0;
}
