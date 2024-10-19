#pragma once

#include"Employee.h"
#include"EmployeeManager.h"
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
        << "3- add Client\n"
        << "4- show Clients\n"
        << "5- search for a client\n"
        << "6- edit client info \n"
        << "7- Logout\n";


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
    cout << "Enter The New Employee Name : \n";
    cin >> name;
    while (!Validation::validationName(name)) {
        cout << "Please Enter Valid Name : \n";
        cin >> name;
    }
    cout << "Enter The New Employee Password : \n";
    cin >> pass;
    while (!Validation::validationPass(pass)) {
        cout << "Please Enter Valid Password : \n";
        cin >> pass;
    }
    cout << "Enter The New Employee Salary : \n";
    cin >> salary;
    while (!Validation::validationSalary(salary)) {
        cout << "Please Enter Valid Salary : (Min: 5000 L.E)\n";
        cin >> salary;
    }
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
    while (op < 1 || op > 7) {
            cout << "Invalid option." << endl;
            cin >> op;
        }
    switch (op) {
    case 1:
        system("cls");
        admin->listEmployee();
        break;
    case 2:
        system("cls");
        newEmployee(admin);
        x.updateEmployeesData();
        break;
    case 3:
        system("cls");
        EmployeeManager::newClient(admin);
        x.updateClientsData();
        break;
    case 4:
        system("cls");
        EmployeeManager::listAllClients(admin);
        break;
    case 5:
        system("cls");
        EmployeeManager::searchForClient(admin);
        break;
    case 6:
        system("cls");
        EmployeeManager::editClientInfo(admin);
        break;
    case 7:
        return false;
    default:
        cout << "Invalid option.\n";

    }
    return true;  
}


};

