#include "mittari.h"
#include "lcd.h"
#include "dht.h"
#include <iostream>

using namespade std

mittari::mittari() {
public:
    Mittari();
    ~Mittari();
    void setup();
    void mittaus();

private:


}

mittari::Mittari()
{
    cout<<"mittari luotu"<<endl;
    setup();
}

mittari::~Mittari()
{
    cout<<"mittari tuhottu"<<endl;
}

void mittari::setup()
{
    varoitusvalo = 0;
    lcdolio.begin();
    dhtolio.begin();
}

void mittari::mittaus()
{
    float t = dhtolio.readTemperature();
    if (t<10){
        varoitusvalo = 1;
    else {
        varoitusvalo = 0;
        }
    }

    if (varoitusvalo == 1){
        cout<<"lampotila liian alhainen"<<endl;
    }
    string s = lcdolio.floatToString(t);
    lcdolio.print(s);

}
