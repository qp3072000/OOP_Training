#pragma once
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string ID;
public:
    Person(const string& _name, int _age, string _ID);
    string getName();
    int getAge();
    string getID();
};