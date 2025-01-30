#include "Luottotili.h"
#include <iostream>
using namespace std;

Luottotili::Luottotili(string omistaja, double luottoRaja)
    : Pankkitili(omistaja), luottoRaja(luottoRaja) {}

bool Luottotili::deposit(double summa) {
    if (summa > 0) {
        saldo += summa;
        if (saldo > 0) saldo = 0;
        return true;
    }
    return false;
}

bool Luottotili::withdraw(double summa) {
    if (summa > 0 && (saldo - summa >= -luottoRaja)) {
        saldo -= summa;
        return true;
    }
    return false;
}

double Luottotili::getLuottoRaja() {
    return luottoRaja;
}
