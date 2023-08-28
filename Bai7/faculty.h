#pragma once

#include"person.h"

class FacultyMember {
private:
    int teacherId;
    double basicSalary;
    double bonusSalary;
    double penalty;
public:
    FacultyMember(int _teacherId, double _basicSalary, double _bonusSalary, double _penalty);
    double calculateNetSalary();
    void displayInfo();
};