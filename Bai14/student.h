#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InvalidFullNameException {};
class InvalidDOBException {};
class InvalidPhoneNumberException {};

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
    
    virtual void ShowMyInfo() const = 0; // Phương thức ảo pure virtual
    virtual bool IsGood() const = 0; // Phương thức ảo pure virtual
    
    const string& GetFullName() const;
    const string& GetPhoneNumber() const;
};
