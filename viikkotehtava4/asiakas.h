#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "Pankkitili.h"
#include "Luottotili.h"
#include <string>
using namespace std;

class Asiakas {
private:
    string nimi;
    Pankkitili* kayttotili;
    Luottotili* luottotili;

public:
    Asiakas(string nimi, Pankkitili* tili, Luottotili* luotto);
    string getNimi();
    void showSaldo();
    bool talletus(double summa);
    bool nosto(double summa);
    bool luotonMaksu(double summa);
    bool luotonNosto(double summa);
    bool tiliSiirto(double summa, Asiakas& kohde);
    ~Asiakas();
};

#endif // ASIAKAS_H
