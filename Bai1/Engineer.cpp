#include "Engineer.h"
#include<iostream>

void Engineer::displayInfor() {
    Officer::displayInfor();
    cout << "Branch: " << branch << endl;
}