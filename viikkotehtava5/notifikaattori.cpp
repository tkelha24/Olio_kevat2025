#include "Notifikaattori.h"
#include <iostream>
#include "seuraaja.h"
#include <string>

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {
    cout<<"Luodaan notifikaattori"<<endl;
}

Notifikaattori::~Notifikaattori() {
    while (seuraajat) {
        Seuraaja* temp = seuraajat;
        seuraajat = seuraajat->next;
        delete temp;
    }
}

// **Lisäys alkuun ("kiilaamalla")**
void Notifikaattori::lisaa(Seuraaja* uusi) {
    if (!uusi) return;

    uusi->next = seuraajat;  // Uusi alkio osoittaa vanhaan alkuun
    seuraajat = uusi;        // Alku päivitetään osoittamaan uuteen alkioon
    cout<<"Notifikaattori lisaa seuraajan "<<uusi->getNimi()<<endl;
}

void Notifikaattori::poista(Seuraaja* poistettava) {
    if (!seuraajat || !poistettava) return;  // Jos lista on tyhjä tai osoitin virheellinen, lopetetaan

    if (seuraajat == poistettava) {  // Jos poistettava on ensimmäinen solmu
        seuraajat = seuraajat->next;
        return;
    }

    Seuraaja* temp = seuraajat;
    while (temp->next && temp->next != poistettava) {
        temp = temp->next;
    }

    if (temp->next) {
        temp->next = temp->next->next;  // Ohitetaan poistettava solmu
    }
}

void Notifikaattori::tulosta() {
    cout << "Notifikaattorin seuraajat:"<<endl;
    for (Seuraaja* temp = seuraajat; temp; temp = temp->next) {
        cout<< "Seuraaja "<<temp->getNimi()<<endl;
    }
}

void Notifikaattori::postita(const string& viesti) {
    std::cout << "Notifikaattori postaa viestin: " << viesti <<endl;

    if (!seuraajat) {  // Jos lista on tyhjä, lopetetaan
        cout << "Ei seuraajia, viestia ei laheteta." <<endl;
        return;
    }

    Seuraaja* temp = seuraajat;
    while (temp) {
        cout << "Lahetetaan seuraajalle: " << temp->getNimi() <<endl;
        temp->paivitys(viesti);
        temp = temp->next;
    }
}
