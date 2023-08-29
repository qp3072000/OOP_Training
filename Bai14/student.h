#pragma once
#include <string>

using namespace std;

class Student {
protected:
    string fullName;
    string doB;
    string sex;
    string phoneNumber;
    string universityName;
    string gradeLevel;

public:
    Student(const string& fullName, const string& doB, const string& sex,
        const string& phoneNumber, const string& universityName, const string& gradeLevel);
    virtual ~Student();
    virtual string GetStudentType() const{
        return "Student";
    }
    
    virtual void ShowMyInfo() const = 0; // Phương thức ảo pure virtual
    virtual bool IsGood() const = 0; // Phương thức ảo pure virtual
    
    const string& GetFullName() const;
    const string& GetPhoneNumber() const;
};
