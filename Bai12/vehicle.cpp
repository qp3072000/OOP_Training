#include"vehicle.h"
#include<iostream>

Vehicle::Vehicle(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color) {
    ID = _id;
    manufacturer = _manufacturer;
    year = _year;
    price = _price;
    color = _color;
}

Vehicle::~Vehicle() {}

string Vehicle::getID() {
    return ID;
}

string Vehicle::getManufacturer() {
    return manufacturer;
}

int Vehicle::getYear() {
    return year;
}

double Vehicle::getPrice() {
    return price;
}

string Vehicle::getColor() {
    return color;
}

void Vehicle::displayInfo() {
    cout << "ID: " << ID << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Year: " << year << endl;
    cout << "Price: " << price << endl;
    cout << "Color: " << color << endl;
}