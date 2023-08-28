#include"candidateA.h"

CandidateA::CandidateA(int _id, const string& _name, const string& _address, int _priority)
    :Candidate(_id, _name, _address, _priority) {}

string CandidateA::getSubjectGroup() {
    return "A: Math, Physics, Chemistry"; 
}