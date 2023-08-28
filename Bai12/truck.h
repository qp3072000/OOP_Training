#include"vehicle.h"

class Truck : public Vehicle {
private:
    double loadCapacity;
public:
    Truck(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color, double _loadCapacity);
    void displayInfo();
};