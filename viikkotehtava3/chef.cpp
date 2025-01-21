#include <iostream>
#include "chef.h"
using namespace std;

Chef::Chef(string name) : chefName(name) {
    cout<<"Debug: Kokki "<<chefName<<endl;
}

Chef::~Chef() {
    cout<<"Debug: Destruktori, kokki "<<chefName<<" poistettu"<<endl;
}

int Chef::makeSalad(int ingredients) {
    int servings = ingredients / 5;
     cout<<"Debug: "<<chefName<<" voi tehda "<<servings<<" salaattiannosta."<<endl;
    return servings;
}

int Chef::makeSoup(int ingredients) {
    int servings = ingredients / 3;
    cout<<"Debug: "<<chefName<<" voi tehda "<<servings<<" keittoannosta."<<endl;
    return servings;
}

string Chef::getChefName() {
    return chefName;
}
