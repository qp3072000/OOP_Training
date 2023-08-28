#include"person.h"

Person::Person(const string& _name, int _age, const string& _hometown, int _teacherId) {
    name = _name;
    age = _age;
    hometown = _hometown;
    teacherId = _teacherId;
}
string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

string Person::getHometown() {
    return hometown;
}

int Person::getTeacherId() {
    return teacherId;
}