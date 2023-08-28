#include "student.h"
#include "highschool.h"
#include"common.h"

#include <iostream>

Student inputStudentInfo() {
    string fullName, hometown, schoolClass;
    int age;

    cin.ignore(); 
    cout << "Enter Full Name: ";
    getline(std::cin, fullName);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore(); 
    cout << "Enter Hometown: ";
    getline(cin, hometown);
    cout << "Enter School Class: ";
    getline(std::cin, schoolClass);

    return Student(fullName, age, hometown, schoolClass);
}

int main() {
    HighSchool school;

    while (true) {
        system("cls"); // Clear the screen (Windows specific)

        cout << "===== High School Management Menu =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students who are 20 years old" << endl;
        cout << "3. Count Students with specific age and hometown" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        managementChoice c = static_cast<managementChoice>(choice);

        switch (c) {
            case managementChoice::ADD: {
                Student student = inputStudentInfo();
                school.addStudent(student);
                break;
            }
            case managementChoice::DISPLAY: {
                school.displayTwentyYearsOldStudents();
                break;
            }
            case managementChoice::COUNT: {
                int age;
                string hometown;

                cout << "Enter Age to Count: ";
                cin >> age;
                cin.ignore(); // Clear the input buffer
                cout << "Enter Hometown to Count: ";
                getline(std::cin, hometown);

                int count = school.countStudentWithAgeHometown(age, hometown);
                cout << "Number of students aged " << age << " from " << hometown << ": " << count << endl;

                break;
            }
            case managementChoice::EXIT: {
                cout << "Goodbye!" << endl;
                exit(0);
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }

        std::cout << "Press Enter to continue...";
        std::cin.ignore(); // Clear the newline character
        std::cin.get();    // Wait for the user to press Enter
    }

    return 0;
}
