#include"person.h"
#include"faculty.h"
#include"common.h"

#include<iostream>
#include<vector>

void addFacultyMember(vector<FacultyMember>& facultyList) {
    int teacherId;
    double baseSalary, bonusSalary, penalty;

    cout << "Enter Teacher ID: ";
    cin >> teacherId;
    cout << "Enter Base Salary: $";
    cin >> baseSalary;
    cout << "Enter Bonus Salary: $";
    cin >> bonusSalary;
    cout << "Enter Penalty: $";
    cin >> penalty;

    FacultyMember faculty(teacherId, baseSalary, bonusSalary, penalty);
    facultyList.push_back(faculty);
}

void displayFacultyInfo(FacultyMember& faculty) {
    faculty.displayInfo();
    cout << endl;
}

int main() {
    std::vector<FacultyMember> facultyList;

    while (true) {
        system("cls"); // Clear the screen (Windows specific)

        cout << "===== Faculty Management Menu =====" << endl;
        cout << "1. Add Faculty Member" << endl;
        cout << "2. Display Faculty Information" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        facultyManagement c = static_cast<facultyManagement>(choice);

        switch (c) {
            case facultyManagement::ADD: {
                addFacultyMember(facultyList);
                break;
            }
            case facultyManagement::DISPLAY: {
                if (facultyList.empty()) {
                    cout << "No faculty members to display." << endl;
                } else {
                    cout << "Faculty Information:" << endl;
                    for (FacultyMember& faculty : facultyList) {
                        displayFacultyInfo(faculty);
                    }
                }
                break;
            }
            case facultyManagement::EXIT: {
                cout << "Goodbye!" << endl;
                return 0;
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