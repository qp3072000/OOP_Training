#include "intern.h"
#include <iostream>

Intern::Intern(int id, const string &name, const string &birth, const string &phone, const string &email,
               const string &majors, const string &semester, const string &uniName)
    : Employee(id, name, birth, phone, email, 2), Majors(majors), Semester(semester), UniversityName(uniName) {}

void Intern::ShowInfo() const {
    cout << "Employee Type: Intern" << endl;
    cout << "ID: " << ID << endl;
    cout << "Name: " << FullName << endl;
    cout << "Birth: " << BirthDay << endl;
    cout << "Phone: " << Phone << endl;
    cout << "Email: " << Email << endl;
    cout << "Majors: " << Majors << endl;
    cout << "Semester: " << Semester << endl;
    cout << "University: " << UniversityName << endl;
}