#include "Student.h"
using namespace std;
#include <string>

Student::Student(string name, int age) : name(name), age(age) {

}

void Student::setName(string newName) {
    name = newName;
}
void Student::setAge(int newAge) {
    age = newAge;
}
string Student::getName() {
    return name;
}
int Student::getAge() {
    return age;
}
void Student::printStudentInfo() {
    cout<<"Student "<<name <<" Age "<<age<<endl;
}
