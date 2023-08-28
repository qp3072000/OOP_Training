#include"ManagerOfficer.h"
#include<iostream>

ManagerOfficer::ManagerOfficer() {}
ManagerOfficer::~ManagerOfficer() {
    for(Officer* officer : officers) {
        delete officer;
    }
}

void ManagerOfficer::addOfficer(Officer* officer) {
    officers.push_back(officer);
}

void ManagerOfficer::searchOfficerByName(const string& _name) {
    cout << "The result of search by name " << _name << " :" << endl;
    for(Officer* officer : officers) {
        if(officer->getName() == _name) {
            officer->displayInfor();            
        }
    }
}

void ManagerOfficer::showListInfoOfficer() {
    cout << "List of officer: " << endl;
    for(Officer* officer : officers) {
        officer->displayInfor();
    }
}

void ManagerOfficer::exit() {
    for(Officer* officer : officers) {
        delete officer;
    }
    officers.clear(); 
}
