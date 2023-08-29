#include "management.h"
#include "common.h"
#include <iostream>

using namespace std;

Management::Management() : computerScience("Computer Science") {}

void Management::run() {
    int ch = 0;
    while (ch != 9) {
        cout << "===== Department Management Menu =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Part-Time Student" << endl;
        cout << "3. Regular Student Count" << endl;
        cout << "4. Find Student with Highest Entrance Score" << endl;
        cout << "5. Find Part-Time Students by Location" << endl;
        cout << "6. Find Students with Minimum Average Score" << endl;
        cout << "7. Find Student with Highest Average Score" << endl;
        cout << "8. Sort Students" << endl;
        cout << "9. Count Students by Admission Year" << endl;
        cout << "10. Exit" << endl;
        cout << "======================================" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        departmentMENU c = static_cast<departmentMENU>(choice);
        switch (c) {
        case departmentMENU::ADDSTUDENT: {
            // Add Student
            int studentId;
            string fullName, dateOfBirth;
            int admissionYear;
            float entranceExamScore;
            cout << "Enter Student ID: ";
            cin >> studentId;
            cin.ignore(); // Clear the newline character from the previous input
            cout << "Enter Full Name: ";
            getline(cin, fullName);
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            cin >> dateOfBirth;
            cout << "Enter Admission Year: ";
            cin >> admissionYear;
            cout << "Enter Entrance Exam Score: ";
            cin >> entranceExamScore;

            Student *student = new Student(studentId, fullName, dateOfBirth, admissionYear, entranceExamScore);
            students.push_back(student);
            computerScience.AddStudent(student);
            cout << "Student added successfully." << endl;
            break;
        }
        case departmentMENU::ADDPARTTIME: {
            // Add Part-Time Student
            int studentId;
            string fullName, dateOfBirth;
            int admissionYear;
            float entranceExamScore;
            string trainingLocation;
            cout << "Enter Student ID: ";
            cin >> studentId;
            cin.ignore();
            cout << "Enter Full Name: ";
            getline(cin, fullName);
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            cin >> dateOfBirth;
            cout << "Enter Admission Year: ";
            cin >> admissionYear;
            cout << "Enter Entrance Exam Score: ";
            cin >> entranceExamScore;
            cin.ignore();
            cout << "Enter Training Location: ";
            getline(cin, trainingLocation);

            PartTimeStudent *partTimeStudent = new PartTimeStudent(studentId, fullName, dateOfBirth, admissionYear, entranceExamScore, trainingLocation);
            partTimeStudents.push_back(partTimeStudent);
            computerScience.AddPartTimeStudent(partTimeStudent);
            cout << "Part-Time Student added successfully." << endl;
            break;
        }
        case departmentMENU::REGULAR: {
            // Regular Student Count
            int regularCount = computerScience.GetRegularStudentCount();
            cout << "Regular Student Count: " << regularCount << endl;
            break;
        }
        case departmentMENU::FINDSTUDENT: {
            // Find Student with Highest Entrance Score
            Student *highestEntranceScoreStudent = computerScience.FindStudentWithHighestEntranceScore();
            if (highestEntranceScoreStudent != nullptr)
            {
                cout << "Student with Highest Entrance Exam Score: " << highestEntranceScoreStudent->GetFullName() << endl;
            }
            else
            {
                cout << "No students found." << endl;
            }
            break;
        }
        case departmentMENU::FINDPARTTIME: {
            // Find Part-Time Students by Location
            string location;
            cout << "Enter Training Location: ";
            cin.ignore();
            getline(cin, location);
            vector<PartTimeStudent *> partTimeStudentsInLocation = computerScience.FindPartTimeStudentsByLocation(location);
            cout << "Part-Time Students in Location " << location << ":" << endl;
            for (PartTimeStudent *student : partTimeStudentsInLocation)
            {
                cout << student->GetFullName() << endl;
            }
            break;
        }
        case departmentMENU::MINIMUM: {
            // Find Students with Minimum Average Score
            float minScore;
            cout << "Enter Minimum Average Score: ";
            cin >> minScore;
            vector<Student *> studentsWithMinAverageScore = computerScience.FindStudentsWithMinAverageScore(minScore);
            cout << "Students with Minimum Average Score of " << minScore << " or Higher:" << endl;
            for (Student *student : studentsWithMinAverageScore)
            {
                cout << student->GetFullName() << endl;
            }
            break;
        }
        case departmentMENU::HIGHEST: {
            // Find Student with Highest Average Score
            Student *highestAverageScoreStudent = computerScience.FindStudentWithHighestAverageScore();
            if (highestAverageScoreStudent != nullptr) {
                cout << "Student with Highest Average Score: " << highestAverageScoreStudent->GetFullName() << endl;
            }
            else {
                cout << "No students found." << endl;
            }
            break;
        }
        case departmentMENU::SORT: {
            // Sort Students
            computerScience.SortStudents();
            cout << "Students sorted by admission year." << endl;
            break;
        }
        case departmentMENU::COUNT: {
            // Count Students by Admission Year
            vector<pair<int, int>> admissionYearCounts = computerScience.CountStudentsByAdmissionYear();
            cout << "Count of Students Admitted Each Year:" << endl;
            for (const auto &pair : admissionYearCounts)
            {
                cout << "Year: " << pair.first << ", Count: " << pair.second << endl;
            }
            break;
        }
        case departmentMENU::EXIT: {
            // Exit
            cout << "Exiting the program." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
        }
    }
}

void Management::cleanup() {
    for (Student *student : students) {
        delete student;
    }
    for (PartTimeStudent *partTimeStudent : partTimeStudents) {
        delete partTimeStudent;
    }
}