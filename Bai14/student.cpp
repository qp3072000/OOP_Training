#include "student.h"

Student::Student(const string& fullName, const string& doB, const string& sex,
    const string& phoneNumber, const string& universityName, const string& gradeLevel)
    : fullName(fullName), doB(doB), sex(sex), phoneNumber(phoneNumber), universityName(universityName),
      gradeLevel(gradeLevel) {
}

const string& Student::GetFullName() const {
    return fullName;
}

const string& Student::GetPhoneNumber() const {
    return phoneNumber;
}
