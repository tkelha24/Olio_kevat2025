#include "Pankkitili.h"
#include <string>
using namespace std;

Pankkitili::Pankkitili(string nimi) : omistaja(nimi), saldo(0) {}

Pankkitili::~Pankkitili() {}

double Pankkitili::getBalance() {
    return saldo;
}

bool Pankkitili::deposit(double summa) {
    if (summa > 0) {
        saldo += summa;
        return true;
    }
    return false;
}

bool Pankkitili::withdraw(double summa) {
    if (summa > 0 && saldo >= summa) {
        saldo -= summa;
        return true;
    }
    return false;
}


