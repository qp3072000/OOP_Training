#include"candidate.h"

Candidate::Candidate(int _id, const string& _name, const string& _address, int _priority) {
    id = _id;
    name = _name;
    address = _address;
    priority = _priority;
}

void Candidate::displayInfo() {
    cout << "Candidate ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Priority: " << priority << endl;
}

int Candidate::getID() {
    return id;
}

string Candidate::getName() {
    return name;
}

string Candidate::getAddress() {
    return address;
}

int Candidate::getPriority() {
    return priority;
}
