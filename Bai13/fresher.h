#pragma once
#include<string>
#include"employee.h"

using namespace std;

class Fresher : public Employee {
private:
    string GraduationDate;
    string GraduationRank;
    string Education;

public:
    Fresher(int id, const string& name, const string& birth, const string& phone, const string& email, 
            const string& gradDate, const string& gradRank, const string& edu);

    void ShowInfo() const override;
};