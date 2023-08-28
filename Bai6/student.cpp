#include"student.h"

Student::Student(const string& _name, int _age, const string& _hometown, const string& _schoolClass) {
    name = _name;
    age = _age;
    hometown = _hometown;
    schoolClass = _schoolClass;
}

string Student::getName() {
    return name;
}

int Student::getAge() {
    return age;
}

string Student::getHomeTown() {
    return hometown;
}

string Student::getSchoolClass() {
    return schoolClass;
}