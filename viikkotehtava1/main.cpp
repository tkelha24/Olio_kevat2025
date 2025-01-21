#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int maxnum);

int main()
{
    int maxnum;
    std::cout << "Anna suurin mahdollinen numero: "; //Peli kaatui ilman suurinta mahdollisinta numeroa
    std::cin >> maxnum; // Suurin arvo maaritellaan "maxnumiin"

    int lkm = game(maxnum); //Tama hakee pelaajan lasketut arvaukset funktiosta game()
    std::cout << "Arvatut kerrat: " << lkm << std::endl; //Pelin viimeinen tuloste oikean arvauksen jalkeen
}

    int game(int maxnum) {
        int lkm=0;
        int arvaus=-1;
        int satunnaisluku;

        std::srand(std::time(0));
        satunnaisluku = (std::rand() % maxnum) + 1; //Luku arvotaan valilta 1-maxnum(maaritelty ylaraja)

        std::cout << satunnaisluku << std::endl; //Tama rivi tulostaa arvotun luvun ruudun ylareunaan tarkoituksella

        while(arvaus!=satunnaisluku){ //Niin kauan kuin arvaus on vaara, while-looppi pyorii
            std::cout<<"Anna numeroarvaus"<<std::endl;
            std::cin>>arvaus;
            lkm++;
        if (arvaus>satunnaisluku){
            std::cout<<"Arvaus liian suuri"<<std::endl;
        }
        else if (arvaus<satunnaisluku){
            std::cout<<"Arvaus liian pieni"<<std::endl;
        }
        else {
            std::cout<<"Oikein arvattu!"<<std::endl; //Oikean arvauksen myota peli paattyy ja arvausten lkm palautetaan main-funktioon
        }
        }
        return lkm;
    }
