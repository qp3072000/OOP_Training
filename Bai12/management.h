#ifndef VEHICLEMANAGEMENT_H
#define VEHICLEMANAGEMENT_H

#include "vehicle.h"
#include <vector>

class VehicleManagement {
private:
    vector<Vehicle*> vehicles;

public:
    VehicleManagement();
    ~VehicleManagement();

    void addVehicle(Vehicle* vehicle);
    void removeVehicle(std::string id);
    void findByManufacturer(std::string manufacturer);
    void findByColor(std::string color);
    void displayAll();
};

#endif
