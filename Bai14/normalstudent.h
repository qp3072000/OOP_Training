#pragma once
#include "student.h"

class NormalStudent : public Student {
private:
    int englishScore;
    int entryTestScore;

public:
    NormalStudent(const string& fullName, const string& doB, const string& sex,
        const string& phoneNumber, const string& universityName, const string& gradeLevel,
        int englishScore, int entryTestScore);
    
    int getEnglishScore();

    void ShowMyInfo() const override;
    bool IsGood() const override;
};
