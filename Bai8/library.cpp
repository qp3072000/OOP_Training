#include"library.h"
#include<iostream>

using namespace std;

void Library::addBorrowCard(const BorrowCard& borrowCard) {
    borrowCardList.push_back(borrowCard);
}

void Library::removeBorrowCard(int borrowCode) {
    for(auto it = borrowCardList.begin(); it != borrowCardList.end(); it++) {
        if(it->getBorrowCode() == borrowCode) {
            borrowCardList.erase(it);
            break;
        }
    }
}

void Library::displayBorrowCards() {
    cout << "List of borrow cards:" << endl;
    for (BorrowCard& borrowCard : borrowCardList) {
        cout << "Borrow Code: " << borrowCard.getBorrowCode() << endl;
        cout << "Borrow Date: " << borrowCard.getBorrowDate() << endl;
        cout << "Due Date: " << borrowCard.getDueDate() << endl;
        cout << "Book Number: " << borrowCard.getBookNumber() << endl;
        cout << "Student Information:" << endl;
        const Student& student = borrowCard.getStudent();
        cout << "Full Name: " << student.getFullName() << endl;
        cout << "Age: " << student.getAge() << endl;
        cout << "Class Name: " << student.getClassName() << endl;
        cout << endl;
    }
}