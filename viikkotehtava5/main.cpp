#include "Notifikaattori.h"
#include "seuraaja.h"
#include <iostream>
using namespace std;

int main() {
    Notifikaattori n;

    // Luodaan seuraajat dynaamisesti
    Seuraaja* a = new Seuraaja("A");
    Seuraaja* b = new Seuraaja("B");
    Seuraaja* c = new Seuraaja("C");

    // Lisätään seuraajat listaan
    n.lisaa(a);
    n.lisaa(b);
    n.lisaa(c);

    // Tulostetaan seuraajat
    n.tulosta();

    // Lähetetään ensimmäinen viesti
    n.postita("Tama on viesti 1");

    // Poistetaan B listalta (mutta ei vielä muistista!)
    n.poista(b);

    // Lähetetään toinen viesti (B ei saa sitä enää)
    n.postita("Tama on viesti 2");

    // Vapautetaan dynaamisesti varatut seuraajaoliot
    delete b;  // B on jo poistettu listalta, nyt vapautetaan muisti
    delete a;  // Lopuksi vapautetaan A ja C
    delete c;

    return 0;
}
