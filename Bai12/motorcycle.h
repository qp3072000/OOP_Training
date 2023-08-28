#include"vehicle.h"

class Motorcycle : public Vehicle {
private:
    double power;
public:
    Motorcycle(const string& _id, const string& _manufacturer, int _year, double _price, const string& _color, double _power);
    void dislayInfo();
};