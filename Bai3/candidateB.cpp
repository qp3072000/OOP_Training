#include"candidateB.h"

CandidateB::CandidateB(int _id, const string& _name, const string& _address, int _priority)
    :Candidate(_id, _name, _address, _priority) {}

string CandidateB::getSubjectGroup() {
    return "B: Math, Chemistry, Biology";
}