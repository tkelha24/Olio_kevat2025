#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>
#include "pankkitili.h"
using namespace std;

class Pankkitili {
protected:
    string omistaja;
    double saldo;

public:
    Pankkitili(string nimi);
    virtual ~Pankkitili();
    virtual double getBalance();
    virtual bool deposit(double summa);
    virtual bool withdraw(double summa);
};

#endif // PANKKITILI_H
