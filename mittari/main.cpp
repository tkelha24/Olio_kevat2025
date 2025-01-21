#include <iostream>
#include "lcd.h"
#include "dht.h"
#include "mittari.h"

using namespace std;

int main()
{
    Mittari.M();

    for (int i; i=0; i++){
        mittaus();
    }

    return 0;
}
