#include "town.h"
#include <iostream>
#include <string>

using namespace std;

Town::Town() {}

void Town::inputTownInfo() {
    int n;
    cout << "Enter number of family: ";
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        int numberOfMember, houseNumber;
        cout << "Enter the number of members in the household " << i + 1 << ": ";
        cin >> numberOfMember;
        
        cout << "Enter the house number of the household " << i + 1 << ": ";
        cin >> houseNumber;

        Family family(numberOfMember, houseNumber);

        for(int j = 0; j < numberOfMember; j++) {
            string name, occupation;
            int age, ID;

            cout << "Enter information for person " << j + 1 << ":" << endl;
            cout << "Enter name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter occupation: ";
            cin.ignore();
            getline(cin, occupation);
            cout << "Enter ID: ";
            cin >> ID;
            cin.ignore();

            People person(name, age, occupation, ID);
            family.addPerson(person);
        }
        familyList.push_back(family);
    }
}

void Town::displayTownInfo() {
    cout << "Information about households in the neighborhood: " << endl;

    for (int i = 0; i < familyList.size(); i++) {
        cout << "Household No: " << i + 1 << ":" << endl;
        cout << "House Number " << familyList[i].getHouseNumber() << endl;
        cout << "Number of member: " << familyList[i].getNumberOfMember() << endl;
        vector<People> member = familyList[i].getPersonList();
        for (int j = 0; j < member.size(); j++) {
            cout << "Information about the " << j + 1 << ":" << endl;
            cout << "Name: " << member[j].getName() << endl;
            cout << "Age: " << member[j].getAge() << endl;
            cout << "Occupation: " << member[j].getOccupation() << endl;
            cout << "ID: " << member[j].getID() << endl;
        }
        cout << "-----------------------" << endl;
    }
}

