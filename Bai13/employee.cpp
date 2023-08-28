#include "employee.h"
#include <iostream>

using namespace std;

Certificate::Certificate(int id, const string &name, const string &rank, const string &date)
    : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificateDate(date) {}

void Certificate::ShowCertificateInfo() const {
    cout << "Certificate ID: " << CertificatedID << endl;
    cout << "Certificate Name: " << CertificateName << endl;
    cout << "Certificate Rank: " << CertificateRank << endl;
    cout << "Certificate Date: " << CertificateDate << endl;
}

Employee::Employee() : ID(-1), FullName(""), BirthDay(""), Phone(""), Email(""), Employee_type(-1) {}

Employee::Employee(int id, const string &name, const string &birth, const string &phone, const string &email, int type)
    : ID(id), FullName(name), BirthDay(birth), Phone(phone), Email(email), Employee_type(type) {
    Employee_count++;
}

Employee::~Employee() {}

int Employee::GetEmployeeCount() {
    return Employee_count;
}

void Employee::AddCertificate(int id, const string &name, const string &rank, const string &date) {
    Certificate certificate(id, name, rank, date);
    certificates.push_back(certificate);
}

void Employee::ShowCertificates() {
    for (const auto &certificate : certificates) {
        certificate.ShowCertificateInfo();
        cout << "---------------------------" << endl;
    }
}

int Employee::getID() {
    return ID;
}

string Employee::getFullName() {
    return FullName;
}

string Employee::getBirthDay() {
    return BirthDay;
}

string Employee::getPhone() {
    return Phone;
}

string Employee::getEmail() {
    return Email;
}

int Employee::getEmployeeType() {
    return Employee_type;
}
