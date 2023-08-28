#pragma once
#include<string>
#include<vector>

using namespace std;

class Student {
private:
    int studentId;
    string fullName;
    string birthDate;
    int admissionYear;
    float entranceExamScore;
    vector<pair<string, float>> academicRecords; // <semester, average score>
public:
    Student();
    Student(int _studentId, const string& _fullName, const string& _birthDate, int _admissionYear, float _entranceExamScore);
    Student(const Student& other);

    void Input();
    void Output();

    bool IsRegularStudent() const;

    float GetAverageScore(const string& semester);

    int GetStudentId();
    string GetFullName();
    int GetAdmissionYear() const;
    float GetEntranceExamScore() const;
    vector<pair<string, float>> GetAcademicRecords() const;
};