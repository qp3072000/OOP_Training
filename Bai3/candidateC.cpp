#include"candidateC.h"

CandidateC::CandidateC(int _id, const string& _name, const string& _address, int _priority)
        :Candidate(_id, _name, _address, _priority) {}

string CandidateC::getSubjectGroup() {
    return "Literature, History, Geography";
}