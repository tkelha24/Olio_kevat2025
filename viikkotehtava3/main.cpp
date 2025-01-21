#include <iostream>
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main() {

    Chef chef1("Gordon");

    chef1.makeSalad(15);
    chef1.makeSoup(9);

    ItalianChef chef2("Mario");

    chef2.makeSalad(15);
    chef2.makeSoup(9);

    string password;
    int flourAmount, waterAmount;

    cout<<"Anna salasana: ";
    cin>>password;

    cout<<"Anna jauhojen maara: ";
    cin>>flourAmount;

    cout << "Anna veden maara: ";
    cin >> waterAmount;

    bool success = chef2.askSecret(password, flourAmount, waterAmount);

    if (success) {
        cout<<"Pizzat valmistettu!"<<endl;
    } else {
        cout<<"Pizzaa ei voida valmistaa."<<endl;
    }

        return 0;
    }
