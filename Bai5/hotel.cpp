#include "hotel.h"
#include <iostream>

Hotel::Hotel() {}

void Hotel::addCustomer(const Person& person, const string& idNumber, int numDays, char roomType) {
    customerList.push_back(person);
    roomList.push_back({roomType, numDays, idNumber});
}

bool Hotel::removeCustomer(const string& idNumber) {
    for (size_t i = 0; i < customerList.size(); ++i) {
        if (roomList[i].idNumber == idNumber) {
            customerList.erase(customerList.begin() + i);
            roomList.erase(roomList.begin() + i);
            std::cout << "Successfully removed!" << std::endl;
            return true;
        }
    }
    std::cout << "Customer with ID number " << idNumber << " not found." << std::endl;
    return false;
}

void Hotel::calculateBill(const std::string& idNumber) {
    int totalBill = 0;
    for (size_t i = 0; i < roomList.size(); ++i) {
        if (roomList[i].idNumber == idNumber) {
            char roomType = roomList[i].roomType;
            int numDays = roomList[i].numDays;

            int roomPrice = (roomType == 'A') ? priceRoomA : (roomType == 'B') ? priceRoomB : priceRoomC;
            int bill = roomPrice * numDays;

            cout << "Bill for customer with ID " << idNumber << " is: $" << bill << endl;
            return;
        }
    }
    std::cout << "Customer with ID number " << idNumber << " not found." << std::endl;
}

void Hotel::printCustomerInfo() {
    cout << "Customer list:" << endl;
    for (size_t i = 0; i < customerList.size(); ++i) {
        cout << "Full Name: " << customerList[i].getName() << ", Age: " << customerList[i].getAge() << ", ID: " << roomList[i].idNumber << endl;
    }
}
