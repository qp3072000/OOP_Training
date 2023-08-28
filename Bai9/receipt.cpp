#include"receipt.h"

Receipt::Receipt(int _previousElectric, int _newElectric, Customer _customer) {
    previousElectric = _previousElectric;
    newElectric = _newElectric;
    customer = _customer;
    calculateElectricityCost();
}

void Receipt::calculateElectricityCost() {
    amountDue = (newElectric - previousElectric) * 5;
}

void Receipt::displayReceipt() {
    cout << "Receipt Information:" << endl;
    customer.displayInfo();
    cout << "Previous Electric Reading: " << previousElectric << endl;
    cout << "Current Electric Reading: " << newElectric << endl;
    cout << "Amount Due: " << amountDue << endl;
}

