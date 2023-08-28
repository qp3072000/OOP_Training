#pragma once

#include <string>
#include <vector>

using namespace std;

#include "student.h"
#include "parttimestudent.h"

class Department {
private:
    string departmentName;
    vector<Student*> students;
    vector<PartTimeStudent*> partTimeStudents;

public:
    // Constructors
    Department(const string& departmentName);
    Department(const Department& other);

    // Add a student to the department
    void AddStudent(Student* student);
    void AddPartTimeStudent(PartTimeStudent* student);

    // Get the number of regular students in the department
    int GetRegularStudentCount();

    // Find the student with the highest entrance exam score in the department
    Student* FindStudentWithHighestEntranceScore();

    // Find PartTimeStudents by training location
    vector<PartTimeStudent*> FindPartTimeStudentsByLocation(const string& location);

    // Find students with a minimum average score in the last semester
    vector<Student*> FindStudentsWithMinAverageScore(float minScore);

    // Find students with the highest average score across all semesters
    Student* FindStudentWithHighestAverageScore();

    // Sort students by type (regular/part-time) and admission year
    void SortStudents();

    // Count the number of students admitted each year
    vector<pair<int, int>> CountStudentsByAdmissionYear();
};
