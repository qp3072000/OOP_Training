#include "Staff.h"
#include <iostream>


void Staff::displayInfor() {
    Officer::displayInfor();
    cout << "Task: " << task << endl;
}