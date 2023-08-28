#include "hotel.h"
#include <iostream>

using namespace std;

int main() {
    Hotel hotel;

    while (true) {
        cout << "===== Hotel Management Menu =====" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Remove Customer" << endl;
        cout << "3. Calculate Bill" << endl;
        cout << "4. Print Customer Info" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string fullName, idNumber;
                int age;
                char roomType;
                int numDays;

                cout << "Enter Full Name: ";
                cin.ignore(); // Clear the newline character from previous input
                getline(cin, fullName);
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter ID Number: ";
                cin >> idNumber;
                cout << "Enter Room Type (A, B, or C): ";
                cin >> roomType;
                cout << "Enter Number of Days: ";
                cin >> numDays;

                Person person(fullName, age, idNumber);
                hotel.addCustomer(person, idNumber, numDays, roomType);

                break;
            }
            case 2: {
                string idNumber;
                cout << "Enter ID Number to Remove: ";
                cin >> idNumber;
                hotel.removeCustomer(idNumber);
                break;
            }
            case 3: {
                string idNumber;
                cout << "Enter ID Number to Calculate Bill: ";
                cin >> idNumber;
                hotel.calculateBill(idNumber);
                break;
            }
            case 4: {
                hotel.printCustomerInfo();
                break;
            }
            case 5: {
                cout << "Goodbye!" << endl;
                exit(0);
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();   
    }

    return 0;
}
