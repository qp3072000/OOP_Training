#include <iostream>
#include<algorithm>

#include"student.h"
#include"normalstudent.h"
#include"goodstudent.h"
#include "management.h"

using namespace std;

void Management::AddStudent(vector<Student*>& students) {
    cout << "Enter Full Name: ";
    string fullName;
    cin.ignore();
    getline(cin, fullName);

    cout << "Enter Date of Birth (dd/MM/YYYY): ";
    string doB;
    cin >> doB;

    cout << "Enter Sex: ";
    string sex;
    cin >> sex;

    cout << "Enter Phone Number: ";
    string phoneNumber;
    cin >> phoneNumber;

    cout << "Enter University Name: ";
    string universityName;
    cin.ignore();
    getline(cin, universityName);

    cout << "Enter Grade Level: ";
    string gradeLevel;
    cin >> gradeLevel;

    // Check for good student or normal student
    cout << "Is this student good? (1 for GoodStudent, 0 for NormalStudent): ";
    int isGood;
    cin >> isGood;

    if (isGood) {
        cout << "Enter GPA: ";
        double gpa;
        cin >> gpa;

        cout << "Enter Best Reward Name: ";
        string bestRewardName;
        cin.ignore();
        getline(cin, bestRewardName);

        students.push_back(new GoodStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName));
    } else {
        cout << "Enter English Score: ";
        int englishScore;
        cin >> englishScore;

        cout << "Enter Entry Test Score: ";
        int entryTestScore;
        cin >> entryTestScore;

        students.push_back(new NormalStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore));
    }
}

void Management::ShowHiredStudents(const vector<Student*>& hiredStudents) {
    cout << "\nHired Students:\n";
    for (const auto& student : hiredStudents) {
        student->ShowMyInfo();
        cout << "---------------------------\n";
    }
}

void Management::HireStudents(vector<Student*>& students, vector<Student*>& hiredStudents) {
    // Sắp xếp danh sách sinh viên theo điểm tốt nghiệp và tên nếu cùng điểm
    sort(students.begin(), students.end(), [](const Student* a, const Student* b) {
        if (a->IsGood() != b->IsGood()) {
            return a->IsGood() > b->IsGood();
        }
        return a->GetFullName() < b->GetFullName();
    });

    // Lựa chọn ứng viên phù hợp cho công ty
    for (int i = 0; i < min(static_cast<int>(students.size()), 15); ++i) {
        if (i < 11) {
            hiredStudents.push_back(students[i]);
        } else {
            delete students[i];
        }
    }
}
