#include "Asiakas.h"
#include <iostream>

using namespace std;

Asiakas::Asiakas(string nimi, Pankkitili* tili, Luottotili* luotto) {
    this->nimi = nimi;
    this->kayttotili = tili;
    this->luottotili = luotto;
}

string Asiakas::getNimi() {
    return nimi;
}

void Asiakas::showSaldo() {
    cout << "Kayttotilin saldo: " << kayttotili->getBalance() << endl;
    cout << "Luottotilin saldo: " << luottotili->getBalance() << endl;
}

bool Asiakas::talletus(double summa) {
    if (summa <= 0) {
        cout << "Virhe: talletussumma ei voi olla negatiivinen tai nolla.\n";
        return false;
    }
    return kayttotili->deposit(summa);
}

bool Asiakas::nosto(double summa) {
    if (summa <= 0) {
        cout << "Virhe: nostosumma ei voi olla negatiivinen tai nolla.\n";
        return false;
    }
    return kayttotili->withdraw(summa);
}

bool Asiakas::luotonNosto(double summa) {
    if (summa <= 0) {
        cout << "Virhe: luoton nostosumma ei voi olla negatiivinen tai nolla.\n";
        return false;
    }
    return luottotili->withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa) {
    if (summa <= 0) {
        cout << "Virhe: luoton maksusumma ei voi olla negatiivinen tai nolla.\n";
        return false;
    }
    return luottotili->deposit(summa);
}

bool Asiakas::tiliSiirto(double summa, Asiakas& kohde) {
    if (summa <= 0) {
        cout << "Virhe: siirtosumma ei voi olla negatiivinen tai nolla.\n";
        return false;
    }

    if (this->nosto(summa)) {
        return kohde.talletus(summa);
    }

    cout << "Tilisiirto epaonnistui: ei tarpeeksi saldoa.\n";
    return false;
}

Asiakas::~Asiakas() {
    cout << "Asiakas " << nimi << " poistettu.\n";
}
