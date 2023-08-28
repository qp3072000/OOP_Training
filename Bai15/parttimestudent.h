#pragma once

#include"student.h"

using namespace std;

class PartTimeStudent : public Student {
private:
    string trainingLocation;
public:
    PartTimeStudent();
    PartTimeStudent(int _studentId, const string& _fullName, const string& _birthDate,
                    int _admissionYear, float _entranceExamScore, const string& _trainingLocation);
    PartTimeStudent(const PartTimeStudent& other);

    // Input and Output methods specific to PartTimeStudent
    void Input();
    void Output();

    // Getter for training location
    string GetTrainingLocation() const;
};