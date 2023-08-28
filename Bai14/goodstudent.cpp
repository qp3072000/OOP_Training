#include "goodstudent.h"

GoodStudent::GoodStudent(const string& fullName, const string& doB, const string& sex,
    const string& phoneNumber, const string& universityName, const string& gradeLevel,
    double gpa, const string& bestRewardName)
    : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {
}

void GoodStudent::ShowMyInfo() const {
    cout << "Full Name: " << fullName << endl;
    cout << "Date of Birth: " << doB << endl;
    cout << "Sex: " << sex << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "University Name: " << universityName << endl;
    cout << "Grade Level: " << gradeLevel << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Best Reward Name: " << bestRewardName << endl;
}

bool GoodStudent::IsGood() const {
    return true;
}
