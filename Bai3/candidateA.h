#pragma once
#include"candidate.h"

class CandidateA:public Candidate {
public:
    CandidateA(int _id, const string& _name, const string& _address, int _priority);
    string getSubjectGroup();
};
