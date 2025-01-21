#include <iostream>
#include "ItalianChef.h"
using namespace std;

ItalianChef::ItalianChef(string name) : Chef(name), password("pizza"), flour(10), water(10) {
    cout << "Debug: Kokki "<<getChefName()<<endl;
}

ItalianChef::~ItalianChef() {
}

int ItalianChef::makeSalad(int ingredients) {
    int servings = ingredients / 5;
    cout<<"Debug: "<<getChefName()<<" voi tehda "<<servings<<" salaattiannosta."<<endl;
    return servings;
}

int ItalianChef::makeSoup(int ingredients) {
    int servings = ingredients / 3;
    cout<<"Debug: "<<getChefName()<<" voi tehda "<<servings<<" keittoannosta."<<endl;
    return servings;
}

void ItalianChef::makePizza(int flourAmount, int waterAmount) {
    int pizzaCount = min(flourAmount / 5, waterAmount / 5);
    cout<<"Debug: "<<pizzaCount<<" pizzaa tehty!"<<endl;
}

bool ItalianChef::askSecret(string inputPassword, int flourAmount, int waterAmount) {
    if (inputPassword == password) {
        cout<<"Salasana oikein!"<<endl;
        makePizza(flourAmount, waterAmount);
        return true;
    } else {
        cout << "Salasana vaarin!" << endl;
        return false;
    }
}
