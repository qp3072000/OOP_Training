#include"customer.h"

Customer::Customer() {
    fullName = "";
    address = "";
    electricMeterID = "";
}

Customer::Customer(const string& _fullName, string _address, string _electricMeterID) {
    fullName = _fullName;
    address = _address;
    electricMeterID = _electricMeterID;
}

string Customer::getFullName() {
    return fullName;
}

string Customer::getAddress() {
    return address;
}

string Customer::getElectricMeterID() {
    return electricMeterID;
}

void Customer::setFullName(const string& name) {
    fullName = name;
}

void Customer::setAddress(const string& addr) {
    address = addr;
}

void Customer::setElectricMeterID(const string& meterID) {
    electricMeterID = meterID;
}

void Customer::displayInfo() {
    cout << "Full Name: " << fullName << endl;
    cout << "Address: " << address << endl;
    cout << "Electric Meter ID: " << electricMeterID << endl;
}

void Customer::updateInfor(const string& name, const string& addr, const string& meterID) {
    fullName = name;
    address = addr;
    electricMeterID = meterID;
}

void Customer::clearInfo() {
    fullName = "";
    address = "";
    electricMeterID = "";
}
