#pragma once

#include"Employee.h"
#include "Admin.h"
#include"FillData.h"
#include"FilesHelper.h"
#include "FilesManager.h"
class AdminManager
{


public:
static void printEmployeeMenu() {
	cout << "1- Show Employees\n"
		<< "2- Add Employee\n"
		<< "3- Logout\n";
	}

static Admin* login(int id, string password) {
    for (int i = 0; i < AllAdmins.size(); i++) {
        if (AllAdmins[i].getId() == id && AllAdmins[i].getPassword() == password) {

            return &AllAdmins[i];
        }
    }
    
    return nullptr;
}

static void newEmployee(Admin* admin) {
    string name, pass;
    double salary;
    name = FillData::enterName();
    pass = FillData::enterPassword();
    salary = FillData::enterBalance();
    int id = FilesHelper::getLast("LastEmployeeId.txt") + 1;

    Employee x(id, name, pass, salary);

    admin->addEmployee(x);

    FilesHelper::saveLast("LastEmployeeId.txt", id);


}


static bool AdminOptions(Admin* admin) {
    int op;
    FilesManager x;

    printEmployeeMenu();
    cin >> op;
    while (op < 1 || op > 3) {
            cout << "Invalid option." << endl;
            cin >> op;
        }
    switch (op) {
    case 1:
        admin->listEmployee();
        break;
    case 2:
        newEmployee(admin);
        x.updateEmployeesData();
        break;
    case 3:
        return false;  
    default:
        cout << "Invalid option.\n";
    }
    return true;  
}


};

