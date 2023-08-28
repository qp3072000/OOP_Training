#pragma once

#include"family.h"
#include<vector>

class Town {
private:
    vector<Family> familyList;
public:
    Town();
    void inputTownInfo();
    void displayTownInfo();
};
