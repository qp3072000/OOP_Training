#include "Department.h"
#include <algorithm>
#include <map>

using namespace std;

// Constructors
Department::Department(const string& departmentName) {
    this->departmentName = departmentName;
}

Department::Department(const Department& other) {
    departmentName = other.departmentName;
    students = other.students;
    partTimeStudents = other.partTimeStudents;
}

// Add a student to the department
void Department::AddStudent(Student* student) {
    students.push_back(student);
}

void Department::AddPartTimeStudent(PartTimeStudent* student) {
    partTimeStudents.push_back(student);
}

// Get the number of regular students in the department
int Department::GetRegularStudentCount() {
    int count = 0;
    for (Student* student : students) {
        if (student->IsRegularStudent()) {
            count++;
        }
    }
    return count;
}

// Find the student with the highest entrance exam score in the department
Student* Department::FindStudentWithHighestEntranceScore() {
    if (students.empty()) {
        return nullptr;
    }

    Student* highestScoreStudent = students[0];
    for (Student* student : students) {
        if (student->GetEntranceExamScore() > highestScoreStudent->GetEntranceExamScore()) {
            highestScoreStudent = student;
        }
    }
    return highestScoreStudent;
}

// Find PartTimeStudents by training location
vector<PartTimeStudent*> Department::FindPartTimeStudentsByLocation(const string& location) {
    vector<PartTimeStudent*> matchingStudents;
    for (PartTimeStudent* student : partTimeStudents) {
        if (student->GetTrainingLocation() == location) {
            matchingStudents.push_back(student);
        }
    }
    return matchingStudents;
}

// Find students with a minimum average score in the last semester
vector<Student*> Department::FindStudentsWithMinAverageScore(float minScore) {
    vector<Student*> matchingStudents;
    for (Student* student : students) {
        vector<pair<string, float>> academicRecords = student->GetAcademicRecords();
        if (!academicRecords.empty()) {
            // Get the average score of the last semester
            float lastSemesterScore = academicRecords.back().second;
            if (lastSemesterScore >= minScore) {
                matchingStudents.push_back(student);
            }
        }
    }
    return matchingStudents;
}

// Find students with the highest average score across all semesters
Student* Department::FindStudentWithHighestAverageScore() {
    if (students.empty()) {
        return nullptr;
    }

    Student* highestAverageScoreStudent = students[0];
    float highestAverageScore = 0.0;

    for (Student* student : students) {
        vector<pair<string, float>> academicRecords = student->GetAcademicRecords();
        float totalScore = 0.0;
        int semesterCount = 0;

        for (const auto& record : academicRecords) {
            totalScore += record.second;
            semesterCount++;
        }

        if (semesterCount > 0) {
            float averageScore = totalScore / semesterCount;
            if (averageScore > highestAverageScore) {
                highestAverageScore = averageScore;
                highestAverageScoreStudent = student;
            }
        }
    }
    return highestAverageScoreStudent;
}

// Sort students by type (regular/part-time) and admission year
void Department::SortStudents() {
    // Sort regular students
    sort(students.begin(), students.end(), [](Student* a, Student* b) {
        return a->GetAdmissionYear() < b->GetAdmissionYear();
    });

    // Sort part-time students
    sort(partTimeStudents.begin(), partTimeStudents.end(), [](PartTimeStudent* a, PartTimeStudent* b) {
        return a->GetAdmissionYear() < b->GetAdmissionYear();
    });
}

// Count the number of students admitted each year
vector<pair<int, int>> Department::CountStudentsByAdmissionYear() {
    vector<pair<int, int>> admissionYearCounts;

    // Count regular students by admission year
    map<int, int> regularStudentCounts;
    for (Student* student : students) {
        int admissionYear = student->GetAdmissionYear();
        regularStudentCounts[admissionYear]++;
    }

    // Count part-time students by admission year
    map<int, int> partTimeStudentCounts;
    for (PartTimeStudent* student : partTimeStudents) {
        int admissionYear = student->GetAdmissionYear();
        partTimeStudentCounts[admissionYear]++;
    }

    // Combine the counts into a single vector
    for (const auto& entry : regularStudentCounts) {
        admissionYearCounts.push_back(make_pair(entry.first, entry.second));
    }

    for (const auto& entry : partTimeStudentCounts) {
        // Check if the admission year already exists in the vector
        bool found = false;
        for (auto& countPair : admissionYearCounts) {
            if (countPair.first == entry.first) {
                countPair.second += entry.second;
                found = true;
                break;
            }
        }

        // If the admission year doesn't exist in the vector, add it
        if (!found) {
            admissionYearCounts.push_back(make_pair(entry.first, entry.second));
        }
    }

    return admissionYearCounts;
}
