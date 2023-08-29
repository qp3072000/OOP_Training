#pragma once
#include<string>
#include<vector>

using namespace std;

class Certificate {
private:
    int CertificatedID;
    string CertificateName;
    string CertificateRank;
    string CertificateDate;

public:
    Certificate(int id, const std::string& name, const std::string& rank, const std::string& date);
    void ShowCertificateInfo() const;
};

class Employee {
protected:
    int ID;
    string FullName;
    string BirthDay;
    string Phone;
    string Email;
    int Employee_type;
    static int Employee_count;
    vector<Certificate> certificates;

public:
    Employee();
    Employee(int id, const string& name, const string& birth, const string& phone, const string& email, int type);
    virtual ~Employee();

    virtual void ShowInfo() const = 0; // Abstract method

    static int GetEmployeeCount();
    int getID();
    string getFullName();
    string getBirthDay();
    string getPhone();
    string getEmail();
    int getEmployeeType();

    void setFullName(const string& name);
    void setBirthDay(const string& birth);
    void setPhone(const string& phone);
    void setEmail(const string& email);
    void setEmployeeType(int type);

    void AddCertificate(int id, const std::string& name, const std::string& rank, const std::string& date);
    void ShowCertificates();
};