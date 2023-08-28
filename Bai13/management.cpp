#include "management.h"
#include"fresher.h"
#include"intern.h"
#include"experience.h"
#include"employee.h"

#include <iostream>

using namespace std;

void EmployeeManager::AddEmployee(
    vector<Employee*>& employees) {
    int id, type;
    
    string name, birth, phone, email;

    
    cout << "Enter ID: ";
    
    cin >> id;
    
    cin.ignore();
    
    cout << "Enter Name: ";
    
    getline(
        cin, name);
    
    cout << "Enter Birth: ";
    
    cin >> birth;
    
    cout << "Enter Phone: ";
    
    cin >> phone;
    
    cout << "Enter Email: ";
    
    cin >> email;

    
    cout << "Employee Types:" << 
    endl;
    
    cout << "0. Experience" << 
    endl;
    
    cout << "1. Fresher" << 
    endl;
    
    cout << "2. Intern" << 
    endl;
    
    cout << "Enter Employee Type: ";
    
    cin >> type;

    Employee* newEmployee = nullptr;

    switch (type) {
        case 0: {
            int expYear;
            
            string proSkill;
            
            cout << "Enter Experience Years: ";
            
            cin >> expYear;
            
            cin.ignore();
            
            cout << "Enter Professional Skill: ";
            
            getline(
                cin, proSkill);
            newEmployee = new Experience(id, name, birth, phone, email, expYear, proSkill);
            break;
        }
        case 1: {
            
            string gradDate, gradRank, edu;
            
            cout << "Enter Graduation Date: ";
            
            cin.ignore();
            
            getline(
                cin, gradDate);
            
            cout << "Enter Graduation Rank: ";
            
            getline(
                cin, gradRank);
            
            cout << "Enter Education: ";
            
            getline(
                cin, edu);
            newEmployee = new Fresher(id, name, birth, phone, email, gradDate, gradRank, edu);
            break;
        }
        case 2: {
            
            string majors, semester, uniName;
            
            cout << "Enter Majors: ";
            
            cin.ignore();
            
            getline(
                cin, majors);
            
            cout << "Enter Semester: ";
            
            getline(
                cin, semester);
            
            cout << "Enter University: ";
            
            getline(
                cin, uniName);
            newEmployee = new Intern(id, name, birth, phone, email, majors, semester, uniName);
            break;
        }
        default:
            
            cout << "Invalid Employee Type." << 
            endl;
            return;
    }

    employees.push_back(newEmployee);
}

// Hàm sửa thông tin nhân viên theo ID
void EmployeeManager::EditEmployee(
    vector<Employee*>& employees, int id) {
    for (auto& emp : employees) {
        if (emp->getID() == id) {
            // Tìm thấy nhân viên theo ID, cho phép chỉnh sửa thông tin của nhân viên
            int choice;
            do {
                
                cout << "Edit Menu:" << 
                endl;
                
                cout << "1. Edit Name" << 
                endl;
                
                cout << "2. Edit Birth" << 
                endl;
                
                cout << "3. Edit Phone" << 
                endl;
                
                cout << "4. Edit Email" << 
                endl;
                
                cout << "0. Exit" << 
                endl;
                
                cout << "Enter your choice: ";
                
                cin >> choice;

                switch (choice) {
                    case 1: {
                        
                        string newName;
                        
                        cout << "Enter new Name: ";
                        
                        cin.ignore();
                        
                        getline(
                            cin, newName);
                        emp->getFullName() = newName;
                        
                        cout << "Name updated successfully." << 
                        endl;
                        break;
                    }
                    case 2: {
                        
                        string newBirth;
                        
                        cout << "Enter new Birth: ";
                        
                        cin.ignore();
                        
                        getline(
                            cin, newBirth);
                        emp->getBirthDay() = newBirth;
                        
                        cout << "Birth updated successfully." << 
                        endl;
                        break;
                    }
                    case 3: {
                        
                        string newPhone;
                        
                        cout << "Enter new Phone: ";
                        
                        cin.ignore();
                        
                        getline(
                            cin, newPhone);
                        emp->getPhone() = newPhone;
                        
                        cout << "Phone updated successfully." << 
                        endl;
                        break;
                    }
                    case 4: {
                        
                        string newEmail;
                        
                        cout << "Enter new Email: ";
                        
                        cin.ignore();
                        
                        getline(
                            cin, newEmail);
                        emp->getEmail() = newEmail;
                        
                        cout << "Email updated successfully." << 
                        endl;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        
                        cout << "Invalid choice. Please try again." << 
                        endl;
                }
            } while (choice != 0);
        }
    }
}

// Hàm xóa nhân viên theo ID
void EmployeeManager::DeleteEmployee(
    vector<Employee*>& employees, int id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getID() == id) {
            delete *it;
            employees.erase(it);
            
            cout << "Employee with ID " << id << " deleted successfully." << 
            endl;
            return;
        }
    }
    
    cout << "Employee with ID " << id << " not found." << 
    endl;
}
