#include "Worker.h"
#include<iostream>

void Worker::displayInfor() {
    Officer::displayInfor();
    cout << "Level: " << level << endl;
}