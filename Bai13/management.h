#pragma once

#include"employee.h"
#include<vector>
#include<memory>

using namespace std;

class EmployeeManager {
private:
    vector<unique_ptr<Employee>>& employees;
public:
    EmployeeManager(vector<unique_ptr<Employee>>& employees);

    void AddEmployee();
    void EditEmployee();
    void DeleteEmployee();
    void FindInterns();
    void FindExperiences();
    void FindFreshers();
    void ShowTotalEmployeeCount() const;

    int ShowMenu() const;
    void Run();
};
