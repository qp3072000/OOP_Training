#pragma once

#include <vector>
#include "department.h"
#include "student.h"
#include "parttimestudent.h"

using namespace std;

class Management {
public:
    Management();
    void run();
    void cleanup();

private:
    Department computerScience;
    vector<Student*> students;
    vector<PartTimeStudent*> partTimeStudents;
};
