/*Toteuta alla olevan luokkakaavion mukainen luokka Game
Konstruktorissa parametrinä annetaan maksimiarvo, mille välille 1-maxNumber peli arpoo arvattavan luvun.
Play()-jäsenfunktioon toteutetaan peli.
printGameResult()-jäsenfunktiosta kutsutaan kun peli on päättynyt. Se tulostaa oikean vastauksen
ja kuinka monta arvausta siihen tarvittiin.
Luokan toteutuksessa täytyy olla molemmat otsikkotiedosto Game.h ja luokan toteutus Game.cpp
*/

#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

class Game {

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

public:
    Game(int maxNumber);
    ~Game();
    void play();
    void printGameResult();
};

#endif // GAME_H
