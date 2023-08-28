#include"highschool.h"
#include<iostream>

using namespace std;

void HighSchool::addStudent(const Student& student) {
    studentList.push_back(student);
}

void HighSchool::displayTwentyYearsOldStudents() {
    cout << "Student who are 20 years old: " << endl;
    for(Student& student:studentList) {
        if(student.getAge() == 20) {
            cout << "Name: " << student.getName() << ", Age: " << student.getAge() << ", Hometown: " << student.getHomeTown() << ", Class: " << student.getSchoolClass() << endl;
        }
    }
}

int HighSchool::countStudentWithAgeHometown(int age, string hometown) {
    int count = 0;
    for(Student& student : studentList) {
        if(student.getAge() == age && student.getHomeTown() == hometown) {
            count++;
        }
    }
    return count;
}