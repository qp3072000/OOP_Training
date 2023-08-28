#pragma once
#include"candidate.h"

class CandidateC:public Candidate {
public:
    CandidateC(int _id, const string& _name, const string& _address, int _priority);
    string getSubjectGroup();
};