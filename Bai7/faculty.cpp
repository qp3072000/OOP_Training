#include"faculty.h"
#include<iostream>

using namespace std;

FacultyMember::FacultyMember(int _teacherId, double _basicSalary, double _bonusSalary, double _penalty) {
    teacherId = _teacherId;
    basicSalary = _basicSalary;
    bonusSalary = _bonusSalary;
    penalty = _penalty;
}

double FacultyMember::calculateNetSalary() {
    return basicSalary + bonusSalary - penalty;
}

void FacultyMember::displayInfo() {
    cout << "Teacher ID: " << teacherId << endl;
    cout << "Base Salary: $" << basicSalary << endl;
    cout << "Bonus Salary: $" << bonusSalary << endl;
    cout << "Penalty: $" << penalty << endl;
    cout << "Net Salary: $" << calculateNetSalary() << endl;
}