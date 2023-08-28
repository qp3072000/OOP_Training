#ifndef H_OFFICER_H
#define H_OFFICER_H

#include <string>

using namespace std;

class Officer {
protected:
    string name;
    int age;
    string gender;
    string address;

public:
    Officer(const string& _name, int _age, const string& _gender, const string& _address) {
        name = _name;
        age = _age;
        gender = _gender;
        address = _address;
    }
    virtual ~Officer();
    virtual void displayInfor();
    virtual string getName();
};

#endif
