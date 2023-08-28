#include "experience.h"

Experience::Experience(int id, const string &name, const string &birth, const string &phone, const string &email,
                       int expYear, const string &proSkill)
    : Employee(id, name, birth, phone, email, 0), ExpInYear(expYear), ProSkill(proSkill) {}

void Experience::ShowInfo() const {
    cout << "Employee Type: Experience" << endl;
    cout << "ID: " << ID << endl;
    cout << "Name: " << FullName << endl;
    cout << "Birth: " << BirthDay << endl;
    cout << "Phone: " << Phone << endl;
    cout << "Email: " << Email << endl;
    cout << "Experience Years: " << ExpInYear << endl;
    cout << "Professional Skill: " << ProSkill << endl;
}
