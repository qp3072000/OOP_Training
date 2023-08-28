#pragma once
#include"candidate.h"

class CandidateB : public Candidate {
public:
    CandidateB(int _id, const string& _name, const string& _address, int _priority);
    string getSubjectGroup();
};