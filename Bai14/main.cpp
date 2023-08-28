#include <iostream>
#include <vector>
#include "management.h"
#include "student.h"
#include "goodstudent.h"
#include "normalstudent.h"

using namespace std;

int main() {
    vector<Student*> students;
    vector<Student*> hiredStudents;

    Management manager;
    
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Show Hired Students" << endl;
        cout << "3. Hire Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.AddStudent(students);
                break;
            case 2:
                manager.ShowHiredStudents(hiredStudents);
                break;
            case 3:
                manager.HireStudents(students, hiredStudents);
                break;
            case 4:
                // Clean up memory for remaining students
                for (auto student : students) {
                    delete student;
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
