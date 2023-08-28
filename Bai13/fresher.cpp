#include "fresher.h"
#include<iostream>

Fresher::Fresher(int id, const string &name, const string &birth, const string &phone, const string &email,
                 const string &gradDate, const string &gradRank, const string &edu)
    : Employee(id, name, birth, phone, email, 1), GraduationDate(gradDate), GraduationRank(gradRank), Education(edu) {}

void Fresher::ShowInfo() const {
    cout << "Employee Type: Fresher" << endl;
    cout << "ID: " << ID << endl;
    cout << "Name: " << FullName << endl;
    cout << "Birth: " << BirthDay << endl;
    cout << "Phone: " << Phone << endl;
    cout << "Email: " << Email << endl;
    cout << "Graduation Date: " << GraduationDate << endl;
    cout << "Graduation Rank: " << GraduationRank << endl;
    cout << "Education: " << Education << endl;
}