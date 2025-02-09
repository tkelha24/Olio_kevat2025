#include "Notifikaattori.h"
#include "seuraaja.h"
#include <iostream>
using namespace std;

int main() {
    Notifikaattori n;

    Seuraaja* a = new Seuraaja("A");
    Seuraaja* b = new Seuraaja("B");
    Seuraaja* c = new Seuraaja("C");

    n.lisaa(a);
    n.lisaa(b);
    n.lisaa(c);

    n.tulosta();

    n.postita("Tama on viesti 1");

    n.poista(b);

    n.postita("Tama on viesti 2");

    delete b;
    delete a;
    delete c;

    return 0;
}
