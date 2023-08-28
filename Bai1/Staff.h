#ifndef H_STAFF_H
#define H_STAFF_H
#include"Officer.h"

class Staff : public Officer {
private:
    string task;
public: 
    Staff(const string& _name, int _age, const string& _gender, const string& _address, const string& _task):Officer(_name, _age, _gender, _address) {
        task = _task;
    }
    void displayInfor();
};
#endif