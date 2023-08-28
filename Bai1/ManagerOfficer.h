#ifndef H_MANAGEROFFICER_H
#define H_MANGEROFFICER_H

#include"Officer.h"
#include<vector>

class ManagerOfficer {
private:
    vector<Officer*> officers;
public:
    ManagerOfficer();
    ~ManagerOfficer();

    void addOfficer(Officer* officer);
    void searchOfficerByName(const string& _name);
    void showListInfoOfficer();
    void exit();
};

#endif