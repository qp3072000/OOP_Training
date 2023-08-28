#include"people.h"

People::People() { }
People::People(const string& _name, int _age, const string& _occupation, int _ID) {
    name = _name;
    age = _age;
    occupation = _occupation;
    ID = _ID;
}

string People::getName() {
    return name;
}

void People::setName(const string& _name) {
    name = _name;
}

int People::getAge() {
    return age;
}

void People::setAge(int _age) {
    age = _age;
}

string People::getOccupation() {
    return occupation;
}

void People::setOccupation(const string& _occupation) {
    occupation = _occupation;
}

int People::getID() {
    return ID;
}

void People::setID(int _ID) {
    ID = _ID;
}