#ifndef H_WORKER_H
#define H_WORKER_H
#include "Officer.h"

class Worker : public Officer {
private:
    int level;
public:
    Worker(const string& _name, int _age, const string& _gender, const string& _address, int _level) : Officer(_name, _age, _gender, _address) {
        level = _level;
    }
    void displayInfor();
};

#endif