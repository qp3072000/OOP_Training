#include"parttimestudent.h"

#include<iostream>

using namespace std;

PartTimeStudent::PartTimeStudent() { }
PartTimeStudent::PartTimeStudent(int _studentId, const string& _fullName, const string& _birthDate,
                    int _admissionYear, float _entranceExamScore, const string& _trainingLocation)
                :Student(_studentId, _fullName, _birthDate, _admissionYear, _entranceExamScore) {
                    trainingLocation = _trainingLocation;
}

PartTimeStudent::PartTimeStudent(const PartTimeStudent& other) 
                :Student(other) {
                    trainingLocation = other.trainingLocation;
}

void PartTimeStudent::Input() {
    Student::Input();
    cout << "Enter Training Location: ";
    cin.ignore(); 
    getline(cin, trainingLocation);
}

void PartTimeStudent::Output() {
    Student::Output();
    cout << "Training Location: " << trainingLocation << endl;
}

string PartTimeStudent::GetTrainingLocation() const {
    return trainingLocation;
}