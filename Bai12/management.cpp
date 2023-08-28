#include "management.h"
#include <iostream>

VehicleManagement::VehicleManagement() {}

VehicleManagement::~VehicleManagement() {
    for (auto vehicle : vehicles) {
        delete vehicle;
    }
}

void VehicleManagement::addVehicle(Vehicle* vehicle) {
    vehicles.push_back(vehicle);
}

void VehicleManagement::removeVehicle(string id) {
    bool found = false;
    for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
        if ((*it)->getID() == id) {
            delete *it;
            vehicles.erase(it);
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Vehicle with ID " << id << " not found." << endl;
    }
}

void VehicleManagement::findByManufacturer(string manufacturer) {
    cout << "Vehicles by Manufacturer (" << manufacturer << "):" << endl;
    for (auto vehicle : vehicles) {
        if (vehicle->getManufacturer() == manufacturer) {
            vehicle->displayInfo();
            cout << endl;
        }
    }
}

void VehicleManagement::findByColor(string color) {
    cout << "Vehicles by Color (" << color << "):" << endl;
    for (auto vehicle : vehicles) {
        if (vehicle->getColor() == color) {
            vehicle->displayInfo();
            cout << endl;
        }
    }
}

void VehicleManagement::displayAll() {
    cout << "All Vehicles:" << endl;
    for (Vehicle* vehicle : vehicles) {
        vehicle->displayInfo();
        cout << endl;
    }
}