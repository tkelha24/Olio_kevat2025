#ifndef SEURAAJA_H
#define SEURAAJA_H
using namespace std;
#include <iostream>
#include <string>

class Seuraaja {
private:
    string nimi;

public:
    Seuraaja* next;  // Linkitetyn listan seuraava solmu

    Seuraaja(string);
    string getNimi();
    void paivitys(const string& viesti);
};

#endif
