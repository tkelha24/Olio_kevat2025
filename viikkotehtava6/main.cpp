#include <vector>
#include <algorithm>
#include "Student.h"
using namespace std;

bool compareByName(Student &a, Student &b) {
    return a.getName() < b.getName();
}

bool compareByAge(Student &a, Student &b) {
    return a.getAge() < b.getAge();
}

int main() {
    vector<Student> students;
    int selection;

    do {
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cout << "Exit = 5" << endl;
        cout << "Select: " <<endl;
        cin >> selection;

        switch (selection) {
        case 0: {
            string name;
            int age;
            cout << "Please give name: "<<endl;
            cin >> name;
            cout << "Please give age: "<<endl;
            cin >> age;
            students.push_back(Student(name, age));
            break;
        }
        case 1:
            cout << "\n";
            for (auto &student : students)
                student.printStudentInfo();
            break;

        case 2:
            sort(students.begin(), students.end(), compareByName);
            cout << "\n";
            for (auto &student : students)
                student.printStudentInfo();
            break;

        case 3:
            sort(students.begin(), students.end(), compareByAge);
            cout << "\n";
            for (auto &student : students)
                student.printStudentInfo();
            break;

        case 4: {
            string searchName;
            cout << "Give a name you want to find: "<<endl;
            cin >> searchName;
            bool found = false;
            for (auto &student : students) {
                if (student.getName() == searchName) {
                    cout << "Student found:" << endl;
                    student.printStudentInfo();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found." << endl;
            break;
        }

        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid selection. Try again." << endl;
        }
    } while (selection != 5);

    return 0;
}
