#pragma once

#include"student.h"
#include<vector>

class HighSchool {
private:
    vector<Student> studentList;
public:
    void addStudent(const Student& student);
    void displayTwentyYearsOldStudents();
    int countStudentWithAgeHometown(int age, string hometown);
};