#pragma once
#include"candidate.h"
#include<vector>
#include<memory>

class Admissions {
private:
    vector<unique_ptr<Candidate>> candidates;
public:
    void addCandidate(unique_ptr<Candidate> candidate);
    void displayCandidateInfo(int _id);
    void searchByID(int _id);
    void exitProgram();
};