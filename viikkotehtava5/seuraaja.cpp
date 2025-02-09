#include "Seuraaja.h"
using namespace std;
#include <iostream>
#include <string>

Seuraaja::Seuraaja(string n) : nimi(n), next(nullptr) {
    cout<<"Luodaan seuraaja "<<nimi<<endl;
}

string Seuraaja::getNimi() {
    return nimi;
}

void Seuraaja::paivitys(const string& viesti) {
    cout << "Seuraaja " << nimi << " sai viestin: " << viesti <<endl;
}
