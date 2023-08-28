#pragma once

#include<string>
using namespace std;

class Vehicle {
protected:
    string ID;
    string manufacturer;
    int year;
    double price;
    string color;
public:
    Vehicle(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color);
    virtual ~Vehicle();

    string getID();
    string getManufacturer();
    int getYear();
    double getPrice();
    string getColor();
    virtual void displayInfo();
};