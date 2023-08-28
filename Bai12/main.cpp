#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "truck.h"
#include "motorcycle.h"
#include "management.h"
#include"common.h"

using namespace std;

void InputVehicleInfo(string &id, string &manufacturer, int &year, double &price, string &color) {
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Manufacturer: ";
    cin >> manufacturer;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Color: ";
    cin >> color;
}

int main() {
    VehicleManagement manager;
    
    string id, manufacturer, color, type, engineType;
    int choice, year;
    double price;

    int numSeats = 0;
    double powerOutput = 0.0;
    double loadCapacity = 0.0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Remove Vehicle" << endl;
        cout << "3. Find by Manufacturer" << endl;
        cout << "4. Find by Color" << endl;
        cout << "5. Display All Vehicles" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer


        managementVehicle c = static_cast<managementVehicle>(choice);
        switch (c) {
        case managementVehicle::ADD: {
            cout << "Enter vehicle type (Car, Motorcycle, or Truck): ";
            cin >> type;
            cin.ignore();

            InputVehicleInfo(id, manufacturer, year, price, color);
            if (type == "Car" || type == "Motorcycle" || type == "Truck") {
                if (type == "Car") {
                    cout << "Enter Number of Seats: ";
                    cin >> numSeats;
                }
                else if (type == "Motorcycle") {
                    cout << "Enter Power Output (in HP): ";
                    cin >> powerOutput;
                }
                else if (type == "Truck") {
                    cout << "Enter Load Capacity (in tons): ";
                    cin >> loadCapacity;
                }

                Vehicle *vehicle = nullptr;

                if (type == "Car") {
                    cout << "Enter Engine Type: ";
                    cin.ignore();
                    getline(cin, engineType);
                    vehicle = new Car(id, manufacturer, year, price, color, numSeats, engineType);
                }
                else if (type == "Motorcycle") {
                    vehicle = new Motorcycle(id, manufacturer, year, price, color, powerOutput);
                }
                else if (type == "Truck") {
                    vehicle = new Truck(id, manufacturer, year, price, color, loadCapacity);
                }

                if (vehicle) {
                    manager.addVehicle(vehicle);
                }
                else {
                    cout << "Invalid vehicle type." << endl;
                }
            }
            else {
                cout << "Invalid vehicle type." << endl;
            }

            break;
        }
        case managementVehicle::REMOVE: {
            cout << "Enter ID of the vehicle to remove: ";
            cin >> id;
            manager.removeVehicle(id);
            break;
        }
        case managementVehicle::FINDBYMANUFACTURER: {
            cout << "Enter Manufacturer to search for: ";
            cin >> manufacturer;
            manager.findByManufacturer(manufacturer);
            break;
        }
        case managementVehicle::FINDBYCOLOR: {
            cout << "Enter Color to search for: ";
            cin >> color;
            manager.findByColor(color);
            break;
        }
        case managementVehicle::DISPLAY: 
            manager.displayAll();
            break;
        case managementVehicle::EXIT:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}