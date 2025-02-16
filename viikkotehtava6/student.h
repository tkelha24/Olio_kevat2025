#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string name, int age);
    void setName(string newName);
    void setAge(int newAge);
    string getName();
    int getAge();
    void printStudentInfo();
};

#endif // STUDENT_H
