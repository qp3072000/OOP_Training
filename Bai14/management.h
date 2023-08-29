#pragma once
#include "student.h"
#include<vector>

class StudentManager {
private:
    vector<Student*> students;

public:
    StudentManager();
    ~StudentManager();

    Student* AddStudent();
    void EditStudent(const string& fullName, Student* newStudent);
    void DeleteStudent(const string& fullName);
    void ShowAllStudents() const;
    void SelectQualifiedStudents(int requiredCount) const;
    void Run();
};
