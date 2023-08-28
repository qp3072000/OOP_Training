#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "employee.h"
#include<iostream>

using namespace std;

class Experience : public Employee {
private:
    int ExpInYear;
    std::string ProSkill;

public:
    Experience(int id, const string& name, const string& birth, const string& phone, const string& email, 
               int expYear, const string& proSkill);

    void ShowInfo() const override;
};

#endif 
