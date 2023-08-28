#include"truck.h"
#include<iostream>

using namespace std;

Truck::Truck(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color, double _loadCapacity) 
    :Vehicle(_id, _manufacturer, _year, _price, _color) {
        loadCapacity = _loadCapacity;
}

void Truck::displayInfo() {
    Vehicle::displayInfo();
    cout << "Load Capacity: " << loadCapacity << " tons" << endl;
}