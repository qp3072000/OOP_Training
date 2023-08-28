#pragma once
#include<string>
#include<iostream>

using namespace std;

class Customer {
private:
    string fullName;
    string address;
    string electricMeterID;
public:
    Customer();
    Customer(const string& _fullName, string _address, string _electricMeterID);
    string getFullName();
    string getAddress();
    string getElectricMeterID();
    void setFullName(const string& name);
    void setAddress(const string& addr);
    void setElectricMeterID(const string& meterID);
    void displayInfo();
    void updateInfor(const string& name, const string& addr, const string& meterID);
    void clearInfo();
};