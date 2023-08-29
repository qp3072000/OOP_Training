#include "normalstudent.h"
#include<iostream>

using namespace std;

NormalStudent::NormalStudent(const string& fullName, const string& doB, const string& sex,
    const string& phoneNumber, const string& universityName, const string& gradeLevel,
    int englishScore, int entryTestScore)
    : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore) {
}

int NormalStudent::getEnglishScore() {
    return englishScore;
}

void NormalStudent::ShowMyInfo() const {
    cout << "Full Name: " << fullName << endl;
    cout << "Date of Birth: " << doB << endl;
    cout << "Sex: " << sex << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "University Name: " << universityName << endl;
    cout << "Grade Level: " << gradeLevel << endl;
    cout << "English Score: " << englishScore << endl;
    cout << "Entry Test Score: " << entryTestScore << endl;
}

bool NormalStudent::IsGood() const {
    return false;
}
