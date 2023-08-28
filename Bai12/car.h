#include"vehicle.h"

class Car : public Vehicle {
private:
    int numSeat;
    string engineType;
public:
    Car(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color, int _numSeat, const string& _engineType);
    void displayInfo();
};