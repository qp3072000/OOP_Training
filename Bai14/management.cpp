#include <iostream>
#include <algorithm>

#include "management.h"
#include"goodstudent.h"
#include"normalstudent.h"

using namespace std;

StudentManager::StudentManager() {}

StudentManager::~StudentManager() {
    for (auto student : students) {
        delete student;
    }
}

Student* StudentManager::AddStudent() {
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

        return new GoodStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName);
    } else {
        cout << "Enter English Score: ";
        int englishScore;
        cin >> englishScore;

        cout << "Enter Entry Test Score: ";
        int entryTestScore;
        cin >> entryTestScore;

        return new NormalStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore);
    }
}

void StudentManager::EditStudent(const string& fullName, Student* newStudent) {
    for (auto& student : students) {
        if (student->GetFullName() == fullName) {
            *student = *newStudent;
            return;
        }
    }
    cout << "Student with Full Name " << fullName << " not found." << endl;
}

void StudentManager::DeleteStudent(const string& fullName) {
    auto it = remove_if(students.begin(), students.end(),
        [&fullName](Student* student) {
            return student->GetFullName() == fullName;
        });

    if (it != students.end()) {
        delete *it;
        students.erase(it, students.end());
        cout << "Student with Full Name " << fullName << " deleted successfully." << endl;
    } else {
        cout << "Student with Full Name " << fullName << " not found." << endl;
    }
}

void StudentManager::ShowAllStudents() const {
    if (students.empty()) {
        cout << "No students to display." << endl;
        return;
    }

    for (const auto& student : students) {
        student->ShowMyInfo();
    }
}

void StudentManager::SelectQualifiedStudents(int requiredCount) const {
    vector<Student*> goodStudents;
    vector<Student*> normalStudents;

    for (const auto& student : students) {
        if (dynamic_cast<GoodStudent*>(student) != nullptr) {
            goodStudents.push_back(student);
        } else {
            normalStudents.push_back(student);
        }
    }

    // Sắp xếp danh sách sinh viên khá giỏi theo GPA và họ tên
    sort(goodStudents.begin(), goodStudents.end(),
        [](Student* a, Student* b) {
            if (dynamic_cast<GoodStudent*>(a) != nullptr && dynamic_cast<GoodStudent*>(b) != nullptr) {
                double gpaA = dynamic_cast<GoodStudent*>(a)->getGPA();
                double gpaB = dynamic_cast<GoodStudent*>(b)->getGPA();
                
                if (gpaA == gpaB) {
                    return a->GetFullName() < b->GetFullName();
                }
                return gpaA > gpaB;
            }
            return false;
        });

    // Chọn ứng viên khá giỏi
    int goodStudentCount = min(requiredCount, static_cast<int>(goodStudents.size()));
    for (int i = 0; i < goodStudentCount; ++i) {
        goodStudents[i]->ShowMyInfo();
    }

    // Nếu còn chỗ trống, chọn ứng viên trung bình
    if (goodStudentCount < requiredCount) {
        int remainingCount = requiredCount - goodStudentCount;
        // Sắp xếp danh sách sinh viên trung bình theo điểm TOEIC và họ tên
        sort(normalStudents.begin(), normalStudents.end(),
            [](Student* a, Student* b) {
                if (dynamic_cast<NormalStudent*>(a) != nullptr && dynamic_cast<NormalStudent*>(b) != nullptr) {
                    int englishScoreA = dynamic_cast<NormalStudent*>(a)->getEnglishScore();
                    int englishScoreB = dynamic_cast<NormalStudent*>(b)->getEnglishScore();
                    
                    if (englishScoreA == englishScoreB) {
                        return a->GetFullName() < b->GetFullName();
                    }
                    return englishScoreA > englishScoreB;
                }
                return false;
            });

        // Chọn ứng viên trung bình
        int normalStudentCount = min(remainingCount, static_cast<int>(normalStudents.size()));
        for (int i = 0; i < normalStudentCount; ++i) {
            normalStudents[i]->ShowMyInfo();
        }
    }
}

void StudentManager::Run() {
    int choice = 0;

    while (choice != 6) {
        // Hiển thị menu
        cout << "Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Edit Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Show All Students" << endl;
        cout << "5. Select Qualified Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                // Thêm sinh viên
                AddStudent();
                break;
            }
            case 2: {
                // Sửa thông tin sinh viên
                string fullName;
                cout << "Enter Full Name of Student to Edit: ";
                cin.ignore();
                getline(cin, fullName);

                Student* newStudent = AddStudent();
                EditStudent(fullName, newStudent);
                delete newStudent;
                break;
            }
            case 3: {
                // Xóa sinh viên
                string fullName;
                cout << "Enter Full Name of Student to Delete: ";
                cin.ignore();
                getline(cin, fullName);
                DeleteStudent(fullName);
                break;
            }
            case 4: {
                // Hiển thị danh sách sinh viên
                cout << "List of Students:" << endl;
                ShowAllStudents();
                break;
            }
            case 5: {
                // Chọn ứng viên phù hợp
                int requiredCount;
                cout << "Enter the number of students to select: ";
                cin >> requiredCount;
                SelectQualifiedStudents(requiredCount); 
                break;
            }
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

