#pragma once

#include<string>
using namespace std;

class Student {
private:
    string name;
    int age;
    string hometown;
    string schoolClass;
public:
    Student(const string& _name, int _age, const string& hometown, const string& schoolClass);
    string getName();
    int getAge();
    string getHomeTown();
    string getSchoolClass();
};