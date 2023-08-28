#pragma once
#include <iostream>
using namespace std;

class Candidate {
private:
    int id;
    string name;
    string address;
    int priority;
public:
    Candidate(int _id, const string& _name, const string& _address, int _priority);

    virtual string getSubjectGroup() = 0;
    void displayInfo();
    int getID();
    string getName();
    string getAddress();
    int getPriority();
};