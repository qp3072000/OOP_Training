#include"admission.h"

void Admissions::addCandidate(unique_ptr<Candidate> candidate) {
    candidates.push_back(move(candidate));
}

void Admissions::displayCandidateInfo(int _id) {
    for(const auto& candidate : candidates) {
        if(candidate->getID() == _id) {
            candidate->displayInfo();
            cout << "Subject Group: " << candidate->getSubjectGroup() << endl;
            return;
        }
    }
    cout << "Candidate with ID " << _id << " not found" << endl;
}

void Admissions::searchByID(int _id) {
    for(const auto&  candidate : candidates) {
        if(candidate->getID() == _id) {
            cout << "Candidate with ID" << _id << "found" << endl;
            return;
        }
    }
    cout << "Candidate with ID " << _id << "not found" << endl;
}

void Admissions::exitProgram() {
    cout << "Exiting the program." << endl;
}
