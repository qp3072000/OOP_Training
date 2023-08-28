#ifndef H_ENGINEER_H
#define H_ENGINEER_H

#include "Officer.h"

class Engineer : public Officer {
private:
    string branch;
public:
    Engineer(const string& _name, int _age, const string& _gender, const string& _address, const string& _branch)
    :Officer(_name, _age, _gender, _address) {
        branch = _branch;
    }
    void displayInfor();
};
#endif