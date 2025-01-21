/*Toteuta alla olevan luokkakaavion mukainen luokka Game
Konstruktorissa parametrinä annetaan maksimiarvo, mille välille 1-maxNumber peli arpoo arvattavan luvun.
Play()-jäsenfunktioon toteutetaan peli.
printGameResult()-jäsenfunktiosta kutsutaan kun peli on päättynyt. Se tulostaa oikean vastauksen
ja kuinka monta arvausta siihen tarvittiin.
Luokan toteutuksessa täytyy olla molemmat otsikkotiedosto Game.h ja luokan toteutus Game.cpp
*/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(int maxNumber) : maxNumber(maxNumber), numOfGuesses(0) {
     std::srand(std::time(0));
    randomNumber = (rand() % maxNumber) + 1;
}

Game::~Game(){
    std::cout << "Peli on loppunut ja objekti tuhotaan pinosta." << std::endl;
}

void Game::play() {
    std::cout << "Peli alkaa!" << std::endl;
    while (playerGuess != randomNumber) {
        std::cout << "Anna arvaus (1-" << maxNumber << "): ";
        std::cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess > randomNumber) {
            std::cout << "Numero on liian iso, arvaa uudelleen" << std::endl;
        } else if (playerGuess < randomNumber) {
            std::cout << "Numero on liian pieni, arvaa uudelleen" << std::endl;
        }
        else printGameResult();
    }
}

void Game::printGameResult() {
    std::cout << "Oikein arvattu!" << std::endl;
    std::cout << "Arvausyrityksia oli " << numOfGuesses << "." << std::endl;
}
