#pragma once
#include<string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string hometown;
    int teacherId;
public:
    Person(const string& _name, int _age, const string& _hometown, int _teacherId);
    string getName();
    int getAge();
    string getHometown();
    int getTeacherId();
};