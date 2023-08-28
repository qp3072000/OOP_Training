#include"admission.h"
#include"candidate.h"
#include"candidateA.h"
#include"candidateB.h"
#include"candidateC.h"
#include<memory>
#include<iostream>


using namespace std;

int main() {
    Admissions admission;

    while (true) {
        cout << "University Admission Management System" << endl;
        cout << "1. Add a New Candidate" << endl;
        cout << "2. Display Candidate Info" << endl;
        cout << "3. Search for Candidate by ID" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, priority;
                string name, address;
                cout << "Enter Candidate ID: ";
                cin >> id;
                cout << "Enter Candidate Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Candidate Address: ";
                getline(cin, address);
                cout << "Enter Priority: ";
                cin >> priority;

                int subjectChoice;
                cout << "Select Subject Group:" << endl;
                cout << "1. Group A" << endl;
                cout << "2. Group B" << endl;
                cout << "3. Group C" << endl;
                cout << "Enter your choice (1-3): ";
                cin >> subjectChoice;

                unique_ptr<Candidate> candidate;

                switch (subjectChoice) {
                    case 1:
                        candidate = make_unique<CandidateA>(id, name, address, priority);
                        break;
                    case 2:
                        candidate = make_unique<CandidateB>(id, name, address, priority);
                        break;
                    case 3:
                        candidate = make_unique<CandidateC>(id, name, address, priority);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        continue;
                }

                admission.addCandidate(std::move(candidate));
                cout << "Candidate added successfully." << endl;
                break;
            }
            case 2: {
                int id;
                cout << "Enter Candidate ID to Display Info: ";
                cin >> id;
                admission.displayCandidateInfo(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Candidate ID to Search: ";
                cin >> id;
                admission.searchByID(id);
                break;
            }
            case 4:
                admission.exitProgram();
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
