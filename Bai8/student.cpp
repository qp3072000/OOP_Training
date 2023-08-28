#include<iostream>
#include"student.h"

Student::Student() {
    fullName = "";
    age = 0;
    className = "";
}

Student::Student(const string& _fullName, int _age, const string& _className) {
    fullName = _fullName;
    age = _age;
    className = _className;
}

const string& Student::getFullName() const {
    return fullName;
}

int Student::getAge() const {
    return age;
}

const string& Student::getClassName() const {
    return className;
}