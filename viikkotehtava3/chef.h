#ifndef CHEF_H
#define CHEF_H

#include <string>
using namespace std;

class Chef {
protected:
    string chefName;

public:
   Chef(string);
    ~Chef();
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);
    string getChefName();
};

#endif // CHEF_H
