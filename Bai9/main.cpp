#include <iostream>
#include <string> 
#include <iostream>
#include "customer.h"
#include "receipt.h"
#include"common.h"

using namespace std;

int main() {
    int choice;
    bool quit = false;
    string name, houseNum, meterID;
    Customer customer("John Doe", "123 ABC Street", "CT12345");
    Receipt receipt(1000, 1200, customer);
    receipt.calculateElectricityCost();

    while(!quit){
        cout << "\nMENU:" << endl;
        cout << "1. Display Receipt Information" << endl;
        cout << "2. Update Customer Information" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        menuCustomer c = static_cast<menuCustomer>(choice);

        switch (c) {
            case menuCustomer::DISPLAY:
                receipt.displayReceipt();
                break;
            case menuCustomer::UPDATE:
                cin.ignore();
                cout << "Enter full name: ";
                getline(cin, name);
                cout << "Enter house number: ";
                getline(cin, houseNum);
                cout << "Enter electric meter ID: ";
                getline(cin, meterID);
                
                customer.updateInfor(name, houseNum, meterID);
                break;
            case menuCustomer::EXIT:
                cout << "Exiting the program." << endl;
                quit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
