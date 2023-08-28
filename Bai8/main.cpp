#include "student.h"
#include "borrowcard.h"
#include "library.h"
#include"common.h"

#include <iostream>

using namespace std;

BorrowCard createBorrowCard() {
    int borrowCode, borrowDate, dueDate, bookNumber;
    string fullName, className;
    int age;

    cout << "Enter Borrow Code: ";
    cin >> borrowCode;
    cout << "Enter Borrow Date: ";
    cin >> borrowDate;
    cout << "Enter Due Date: ";
    cin >> dueDate;
    cout << "Enter Book Number: ";
    cin >> bookNumber;
    cin.ignore(); // Clear the newline character
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore(); 
    cout << "Enter Class Name: ";
    getline(cin, className);

    Student student(fullName, age, className);
    BorrowCard borrowCard(borrowCode, borrowDate, dueDate, bookNumber, student);

    return borrowCard;
}

int main() {
    Library library;

    while (true) {
        system("cls"); // Clear the screen (Windows specific)

        cout << "===== Library Management Menu =====" << endl;
        cout << "1. Add Borrow Card" << endl;
        cout << "2. Remove Borrow Card" << endl;
        cout << "3. Display Borrow Cards" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        
        libraryManagement c = static_cast<libraryManagement>(choice);

        switch (c) {
            case libraryManagement::ADD: {
                BorrowCard borrowCard = createBorrowCard();
                library.addBorrowCard(borrowCard);
                break;
            }
            case libraryManagement::REMOVE: {
                int borrowCode;
                cout << "Enter Borrow Code to remove: ";
                cin >> borrowCode;
                library.removeBorrowCard(borrowCode);
                break;
            }
            case libraryManagement::DISPLAY: {
                library.displayBorrowCards();
                break;
            }
            case libraryManagement::EXIT: {
                cout << "Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        cout << "Press Enter to continue...";
        cin.ignore(); 
        cin.get();    // Wait for the user to press Enter
    }

    return 0;
}
