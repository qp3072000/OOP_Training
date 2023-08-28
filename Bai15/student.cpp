#include "Student.h"
#include <iostream>

// Constructors
Student::Student() {
    studentId = 0;
    fullName = "";
    birthDate = "";
    admissionYear = 0;
    entranceExamScore = 0.0;
}

Student::Student(int _studentId, const string& _fullName, const string& _birthDate, int _admissionYear, float _entranceExamScore) {
    studentId = _studentId;
    fullName = _fullName;
    birthDate = _birthDate;
    admissionYear = _admissionYear;
    entranceExamScore = _entranceExamScore;
}

Student::Student(const Student& other) {
    studentId = other.studentId;
    fullName = other.fullName;
    birthDate = other.birthDate;
    admissionYear = other.admissionYear;
    entranceExamScore = other.entranceExamScore;
    academicRecords = other.academicRecords;
}

// Input method
void Student::Input() {
    cout << "Enter Student ID: ";
    cin >> studentId;
    cin.ignore(); // Clear the newline character from the buffer
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter Birth Date: ";
    cin >> birthDate;
    cout << "Enter Admission Year: ";
    cin >> admissionYear;
    cout << "Enter Entrance Exam Score: ";
    cin >> entranceExamScore;
}

// Output method
void Student::Output() {
    cout << "Student ID: " << studentId << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Birth Date: " << birthDate << endl;
    cout << "Admission Year: " << admissionYear << endl;
    cout << "Entrance Exam Score: " << entranceExamScore << endl;
}

// Determine if the student is a regular student
bool Student::IsRegularStudent() const {
    return studentId >= 1000 && studentId < 2000;
}


// Get the average score for a given semester
float Student::GetAverageScore(const string& semester) {
    for (const auto& record : academicRecords) {
        if (record.first == semester) {
            return record.second;
        }
    }
    return 0.0; // Return 0 if the semester is not found
}

// Getters
int Student::GetStudentId() {
    return studentId;
}

string Student::GetFullName() {
    return fullName;
}

int Student::GetAdmissionYear() const {
    return admissionYear;
}

float Student::GetEntranceExamScore() const {
    return entranceExamScore;
}

vector<pair<string, float>> Student::GetAcademicRecords() const {
    return academicRecords;
}
