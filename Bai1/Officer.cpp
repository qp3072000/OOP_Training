#include "Officer.h"
#include<iostream>

Officer::~Officer() {}

void Officer::displayInfor() {
    cout << "Full name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
}

string Officer::getName() {
    return name;
}