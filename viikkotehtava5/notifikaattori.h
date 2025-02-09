#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
using namespace std;
#include <string>
#include "Seuraaja.h"

class Notifikaattori {
private:
    Seuraaja* seuraajat;
public:
    Notifikaattori();
    ~Notifikaattori();
    void lisaa(Seuraaja* seuraaja);
    void poista(Seuraaja* seuraaja);
    void tulosta();
    void postita(const string& viesti);
};

#endif
