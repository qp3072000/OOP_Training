#include <iostream>
#include <vector>
#include <memory>

#include "employee.h"
#include "fresher.h"
#include "intern.h"
#include "experience.h"
#include "management.h"

using namespace std;

int main() {
    vector<unique_ptr<Employee>> employees;
    EmployeeManager manager(employees);
    manager.Run();
    return 0;
}
