#pragma once

#include<iostream>

using namespace std;

class People {
private:
    string name;
    int age;
    string occupation;
    int ID;
public: 
    People();
    People(const string& _name, int _age, const string& _occupation, int _ID);

    string getName();
    void setName(const string& name);
    int getAge();
    void setAge(int _age);
    string getOccupation();
    void setOccupation(const string& _occupation);
    int getID();
    void setID(int _ID);
};