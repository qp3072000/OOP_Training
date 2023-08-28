#pragma once
#include<string>
#include"employee.h"

using namespace std;

class Intern : public Employee {
private:
    string Majors;
    string Semester;
    string UniversityName;

public:
    Intern(int id, const string& name, const string& birth, const string& phone, const string& email, 
           const string& majors, const string& semester, const string& uniName);

    void ShowInfo() const override;
};