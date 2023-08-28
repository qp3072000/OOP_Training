#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>
#include "student.h"

class Management {
public:
    void AddStudent(std::vector<Student*>& students);
    void ShowHiredStudents(const std::vector<Student*>& hiredStudents);
    void HireStudents(std::vector<Student*>& students, std::vector<Student*>& hiredStudents);
};

#endif
