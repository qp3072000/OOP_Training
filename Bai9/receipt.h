#pragma once
#include"customer.h"

class Receipt {
private:
    Customer customer;
    int previousElectric;
    int newElectric;
    int amountDue;
public:
    Receipt(int _previousElectric, int _newElectric, Customer _customer);
    void calculateElectricityCost();
    void displayReceipt();
};
