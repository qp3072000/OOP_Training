#include"car.h"
#include<iostream>
using namespace std;

Car::Car(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color, int _numSeat, const string& _engineType)
    :Vehicle(_id, _manufacturer, _year, _price, _color) {
        numSeat = _numSeat;
        engineType = _engineType;
}

void Car::displayInfo() {
    cout << "Car ID: " << ID << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Year: " << year << endl;
    cout << "Price: $" << price << endl;
    cout << "Color: " << color << endl;
    cout << "Number of Seats: " << numSeat << endl;
    cout << "Engine Type: " << engineType << endl; 
}