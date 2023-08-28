#include"motorcycle.h"
#include<iostream>

using namespace std;

Motorcycle::Motorcycle(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color, double _power) 
    :Vehicle(_id, _manufacturer, _year, _price, _color) {
    power = _power;
}

void Motorcycle::dislayInfo() {
    Vehicle::displayInfo();
    cout << "Power Output: " << power << " HP" << endl;
}