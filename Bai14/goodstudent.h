#pragma once
#include "student.h"

class GoodStudent : public Student {
private:
    double gpa;
    string bestRewardName;

public:
    GoodStudent(const string& fullName, const string& doB, const string& sex,
        const string& phoneNumber, const string& universityName, const string& gradeLevel,
        double gpa, const string& bestRewardName);

    void ShowMyInfo() const override;
    bool IsGood() const override;
};
