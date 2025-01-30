#include <iostream>
#include "Pankkitili.h"
#include "Luottotili.h"
#include "Asiakas.h"

using namespace std;

int main() {
    Pankkitili akuTili("Aku Ankka");
    Luottotili akuLuottotili("Aku Ankka", 1000);
    Asiakas aku("Aku Ankka", &akuTili, &akuLuottotili);

    cout<<"Pankkitili luotu Aku Ankalle" << endl;
    cout<<"Luottotili luotu Aku Ankalle, luottoraja 1000"<<endl;

    aku.talletus(250);
    aku.nosto(150);

    Pankkitili iinesTili("Iines Ankka");
    Luottotili iinesLuottotili("Iines Ankka", 1000);
    Asiakas iines("Iines Ankka", &iinesTili, &iinesLuottotili);

    cout<<"Pankkitili luotu Iines Ankalle"<<endl;
    cout<<"Luottotili luotu Iines Ankalle, luottoraja 1000"<<endl;

    cout<<"Aku Ankka siirtaa 50 euroa Iines Ankalle"<<endl;
    aku.tiliSiirto(50, iines);

    cout<< "Aku Ankka"<<endl;
    aku.showSaldo();

    cout<< "Iines Ankka"<<endl;
    iines.showSaldo();

    return 0;
}
