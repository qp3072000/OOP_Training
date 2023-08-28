#include "ManagerOfficer.h"
#include "Worker.h"
#include "Engineer.h"
#include "Staff.h"
#include "Officer.h"

#include <iostream>
using namespace std;

int main() {
    ManagerOfficer management;

    while (true) {
        cout << "Select a position " << endl;
        cout << "1. Add officer" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Show list information of officer" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Select a position (1. Worker, 2. Engineer, 3. Staff): ";
                int type;
                do {
                    cin >> type;
                } while (type < 1 || type > 3);

                string name;
                int age;
                string gender;
                string address;

                cout << "Enter information of officer:" << endl;
                cin.ignore();
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter gender (male/female/other): ";
                getline(cin, gender);
                cout << "Enter address: ";
                getline(cin, address);

                Officer* officer = nullptr;

                if (type == 1) {
                    int level;
                    cout << "Enter level (1-10): ";
                    cin >> level;
                    officer = new Worker(name, age, gender, address, level);
                } else if (type == 2) {
                    string branch;
                    cin.ignore();
                    cout << "Enter branch: ";
                    getline(cin, branch);
                    officer = new Engineer(name, age, gender, address, branch);
                } else if (type == 3) {
                    string task;
                    cin.ignore(); 
                    cout << "Enter task: ";
                    getline(cin, task);
                    officer = new Staff(name, age, gender, address, task);
                } else {
                    cout << "Invalid officer type. Please re-enter." << endl;
                }

                if (officer != nullptr) {
                    management.addOfficer(officer);
                }

                break;
            }
            case 2: {
                string name;
                cin.ignore(); 
                cout << "Enter name of officer: ";
                getline(cin, name);
                management.searchOfficerByName(name);
                break;
            }
            case 3:
                management.showListInfoOfficer();
                break;
            case 4:
                management.exit();
                return 0; 
            default:
                cout << "Option invalid. Please re-enter." << endl;
                break;
        }
    }

    return 0;
}
