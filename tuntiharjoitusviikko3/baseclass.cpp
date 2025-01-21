#include "baseclass.h"
#include <iostream>
using namespace std;

baseclass::baseclass(int a, int b) {
    cout<<"baseclass muodostettu"<<endl;
    foo=a;
    bar=b;
};

void baseclass::alusta{
    foo = 1;
    bar = 2;
    huuhaa = 3;
}
