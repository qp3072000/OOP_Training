#include "management.h"
#include "employee.h"
#include "fresher.h"
#include "intern.h"
#include "experience.h"
#include <iostream>

using namespace std;

EmployeeManager::EmployeeManager(vector<unique_ptr<Employee>>& employees)
    : employees(employees) {}

void EmployeeManager::Run() {
    while (true) {
        int choice = ShowMenu();

        switch (choice) {
            case 1:
                AddEmployee();
                break;
            case 2:
                EditEmployee();
                break;
            case 3:
                DeleteEmployee();
                break;
            case 4:
                FindInterns();
                break;
            case 5:
                FindExperiences();
                break;
            case 6:
                FindFreshers();
                break;
            case 7:
                ShowTotalEmployeeCount();
                break;
            case 0:
                // Clean up memory
                for (auto& emp : employees) {
                    emp.reset();
                }
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void EmployeeManager::AddEmployee() {
    int id, type;
    string name, birth, phone, email;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Birth: ";
    getline(cin, birth);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Employee Types:" << endl;
    cout << "0. Experience" << endl;
    cout << "1. Fresher" << endl;
    cout << "2. Intern" << endl;
    cout << "Enter Employee Type: ";

    cin >> type;

    Employee* newEmployee = nullptr;

    switch (type) {
        case 0: {
            int expYear;
            string proSkill;
            cout << "Enter Experience Years: ";
            cin >> expYear;
            cin.ignore();

            cout << "Enter Professional Skill: ";
            getline(cin, proSkill);

            newEmployee = new Experience(id, name, birth, phone, email, expYear, proSkill);
            break;
        }
        case 1: {
            string gradDate, gradRank, edu;
            cout << "Enter Graduation Date: ";
            cin.ignore();
            getline(cin, gradDate);

            cout << "Enter Graduation Rank: ";
            getline(cin, gradRank);

            cout << "Enter Education: ";
            getline(cin, edu);

            newEmployee = new Fresher(id, name, birth, phone, email, gradDate, gradRank, edu);
            break;
        }
        case 2: {
            string majors, semester, uniName;
            cout << "Enter Majors: ";
            getline(cin, majors);

            cout << "Enter Semester: ";
            getline(cin, semester);

            cout << "Enter University: ";
            getline(cin, uniName);

            newEmployee = new Intern(id, name, birth, phone, email, majors, semester, uniName);
            break;
        }
        default:
            cout << "Invalid Employee Type." << endl;
            return;
    }

    employees.push_back(unique_ptr<Employee>(newEmployee));
    cout << "Employee added successfully." << endl;
}

void EmployeeManager::EditEmployee() {
    int id;
    cout << "Enter the ID of the employee to edit: ";
    cin >> id;

    for (auto& emp : employees) {
        if (emp->getID() == id) {
            // Tìm thấy nhân viên theo ID, cho phép chỉnh sửa thông tin của nhân viên
            int choice;
            do {
                cout << "Edit Menu:" << endl;
                cout << "1. Edit Name" << endl;
                cout << "2. Edit Birth" << endl;
                cout << "3. Edit Phone" << endl;
                cout << "4. Edit Email" << endl;
                cout << "0. Exit" << endl;
                cout << "Enter your choice: ";

                cin >> choice;

                switch (choice) {
                    case 1: {
                        string newName;
                        cout << "Enter new Name: ";
                        cin.ignore();
                        getline(cin, newName);
                        emp->setFullName(newName);
                        cout << "Name updated successfully." << endl;
                        break;
                    }
                    case 2: {
                        string newBirth;
                        cout << "Enter new Birth: ";
                        cin.ignore();
                        getline(cin, newBirth);
            
                        emp->setBirthDay(newBirth);
                        cout << "Birth updated successfully." << endl;
                        break;
                    }
                    case 3: {
                        string newPhone;
                        cout << "Enter new Phone: ";
                        cin.ignore();
                        getline(cin, newPhone);
                       
                        emp->setPhone(newPhone);
                        cout << "Phone updated successfully." << endl;
                        break;
                    }
                    case 4: {
                        string newEmail;
                        cout << "Enter new Email: ";
                        cin.ignore();
                        getline(cin, newEmail);
                    
                        emp->setEmail(newEmail);
                        cout << "Email updated successfully." << endl;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice != 0);
            return;
        }
    }

    cout << "Employee with ID " << id << " not found." << endl;
}

void EmployeeManager::DeleteEmployee() {
    int id;
    cout << "Enter the ID of the employee to delete: ";
    cin >> id;

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getID() == id) {
            employees.erase(it);
            cout << "Employee with ID " << id << " deleted successfully." << endl;
            return;
        }
    }

    cout << "Employee with ID " << id << " not found." << endl;
}

void EmployeeManager::FindInterns() {
    cout << "List of Interns:" << endl;
    for (const auto& emp : employees) {
        if (dynamic_cast<Intern*>(emp.get())) {
            emp->ShowInfo();
            cout << "---------------------------" << endl;
        }
    }
}

void EmployeeManager::FindExperiences() {
    cout << "List of Experiences:" << endl;
    for (const auto& emp : employees) {
        if (dynamic_cast<Experience*>(emp.get())) {
            emp->ShowInfo();
            cout << "---------------------------" << endl;
        }
    }
}

void EmployeeManager::FindFreshers() {
    cout << "List of Freshers:" << endl;
    for (const auto& emp : employees) {
        if (dynamic_cast<Fresher*>(emp.get())) {
            emp->ShowInfo();
            cout << "---------------------------" << endl;
        }
    }
}

void EmployeeManager::ShowTotalEmployeeCount() const {
    cout << "Total Employee Count: " << employees.size() << endl;
}

int EmployeeManager::ShowMenu() const {
    int choice;

    cout << "Menu:" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Edit Employee" << endl;
    cout << "3. Delete Employee" << endl;
    cout << "4. Find Interns" << endl;
    cout << "5. Find Experiences" << endl;
    cout << "6. Find Freshers" << endl;
    cout << "7. Show Total Employee Count" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    return choice;
}
