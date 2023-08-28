#include"person.h"

Person::Person(const string& _name, int _age, string _ID) {
    name = _name;
    age = _age;
    ID = _ID;
}

string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

string Person::getID() {
    return ID;
}
