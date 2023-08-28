#include"family.h"

Family::Family() {}
Family::Family(int _numberOfMember, int _houseNumber) {
    numberOfMember = _numberOfMember;
    houseNumber = _houseNumber;
}

int Family::getNumberOfMember() {
    return numberOfMember;
}

void Family::setNumberOfMember(int _numberOfMember) {
    numberOfMember = _numberOfMember;
}

int Family::getHouseNumber() {
    return houseNumber;
}

void Family::setHouseNumber(int _houseNumber) {
    houseNumber = _houseNumber;
}

void Family::addPerson(const People& person) {
    people.push_back(person);
}

vector<People> Family::getPersonList() {
    return people;
}