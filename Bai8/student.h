#pragma once
#include<string>

using namespace std;

class Student {
private:
    string fullName;
    int age;
    string className;
public:
    Student();
    Student(const string& _fullName, int _age, const string& _className);
    const string& getFullName() const;
    int getAge() const;
    const string& getClassName() const;
};
