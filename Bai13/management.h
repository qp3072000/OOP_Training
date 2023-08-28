#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include <iostream>
#include <vector>
#include "employee.h" 

class EmployeeManager {
public:
    static void AddEmployee(std::vector<Employee*>& employees);
    static void EditEmployee(std::vector<Employee*>& employees, int id);
    static void DeleteEmployee(std::vector<Employee*>& employees, int id);
};

#endif
