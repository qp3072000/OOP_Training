#include <iostream>
#include <vector>
#include <string>

#include "employee.h"
#include "intern.h"
#include "experience.h"
#include "fresher.h"
#include "management.h"
#include"common.h"

using namespace std;

int Employee::Employee_count = 0;

int main() {
    vector<Employee*> employees;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Edit Employee" << endl;
        cout << "3. Delete Employee" << endl;
        cout << "4. Show Employee Information" << endl;
        cout << "5. Show Total Employee Count" << endl;
        cout << "6. Add Certificate" << endl;
        cout << "7. Show Certificates" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        MENU c = static_cast<MENU>(choice);

        switch (c) {
            case MENU::ADDEMPLOYEE: {
                EmployeeManager::AddEmployee(employees);
                break;
            }
            case MENU::EDITEMPLOYEE: {
                int id;
                cout << "Enter the ID of the employee to edit: ";
                cin >> id;
                EmployeeManager::EditEmployee(employees, id);
                break;
            }
            case MENU::DELETE: {
                int id;
                cout << "Enter the ID of the employee to delete: ";
                cin >> id;
                EmployeeManager::DeleteEmployee(employees, id);
                break;
            }
            case MENU::EMPLOYEEINFORMATION: {
                for (const auto& emp : employees) {
                    emp->ShowInfo();
                    cout << "---------------------------" << endl;
                }
                break;
            }
            case MENU::TOTALEMPLOYEECOUNT: {
                cout << "Total Employee Count: " << Employee::GetEmployeeCount() << endl;
                break;
            }
            case MENU::ADDCERTIFICATE: {
                int empIndex;

                cout << "Enter the index of the employee: ";
                cin >> empIndex;

                int certificateID;
                string certificateName, certificateRank, certificateDate;

                cout << "Enter Certificate ID: ";
                cin >> certificateID;
                cin.ignore();
                cout << "Enter Certificate Name: ";
                getline(cin, certificateName);
                cout << "Enter Certificate Rank: ";
                getline(cin, certificateRank);
                cout << "Enter Certificate Date: ";
                getline(cin, certificateDate);

                employees[empIndex]->AddCertificate(certificateID, certificateName, certificateRank, certificateDate);
                break;
            }
            case MENU::SHOWCERTIFICATE: {
                int empIndex; 

                cout << "Enter the index of the employee: ";
                cin >> empIndex;

                employees[empIndex]->ShowCertificates();
                break;
            }
            case MENU::EXIT: {
                // Clean up memory
                for (auto emp : employees) {
                    delete emp;
                }
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
