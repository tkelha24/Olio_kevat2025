#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class ItalianChef : public Chef {
private:
    string password;
    int flour;
    int water;

    void makePizza(int flour, int water);
public:
    ItalianChef(string name);
    ~ItalianChef();

    int makeSalad(int ingredients);
    int makeSoup(int ingredients);

    bool askSecret(string inputPassword, int flourAmount, int waterAmount);
};

#endif // ITALIANCHEF_H
