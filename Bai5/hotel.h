#pragma once

#include"person.h"
#include<vector>

class Hotel {
private:
    struct Room {
        char roomType;
        int numDays;
        string idNumber;
    };

    vector<Person> customerList;
    vector<Room> roomList;
    const int priceRoomA = 500;
    const int priceRoomB = 300;
    const int priceRoomC = 100;
public:
    Hotel();
    void addCustomer(const Person& person, const string& idNumber, int numDays, char roomType);
    bool removeCustomer(const string& idNumber);
    void calculateBill(const string& idNumber);
    void printCustomerInfo();
};