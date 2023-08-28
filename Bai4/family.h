#pragma once

#include"people.h"
#include<vector>

class Family {
private:
    int numberOfMember;
    int houseNumber;
    vector<People> people;
public:
    Family();
    Family(int _numberOfMember, int _houseNumber);

    int getNumberOfMember();
    void setNumberOfMember(int _numberOfMember);
    int getHouseNumber();
    void setHouseNumber(int _houseNumber);
    void addPerson(const People& person);
    vector<People> getPersonList();
};