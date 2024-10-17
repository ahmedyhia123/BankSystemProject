#pragma once

#include "Employee.h"
#include "Client.h"
#include"FillData.h"
#include "FilesHelper.h"
#include "FilesManager.h"
class EmployeeManager

{
public:

    static void printEmployeeMenu() {
        cout << "1- Add New Client\n"
            << "2- Show All Clients\n"
            << "3- Search for Client\n"
            << "4- Edit Client \n"
            << "5- Logout\n";
    }

    static void newClient(Employee* employee) {
        string name, pass;
        double balance;
        name = FillData::enterName();
        pass = FillData::enterPassword();
        balance = FillData::enterBalance();
        int id = FilesHelper::getLast("LastClientId.txt") + 1;

        Client client(id, name, pass, balance);

        employee->addClient(client);

        FilesHelper::saveLast("LastClientId.txt", id);
    
        
    }
    static void listAllClients(Employee* employee) {

        employee->listClient();
    }

    static void searchForClient(Employee* employee) {
        int id;
        cout << "Please Enter Client ID : \n";
        cin >> id;
        Client* client = employee->searchClient(id);  
        if (client != nullptr) {
            client->displayInfo();  
        }
        else {
            cout << "Client not found.\n";
        }
    }
    static void editClientInfo(Employee* employee) {
        string name, pass;
        double balance;
        int id;
        cout << "Please Enter Client ID : \n";
        cin >> id;

        name = FillData::enterName();
        pass = FillData::enterPassword();
        balance = FillData::enterBalance();
        employee->editClient(id, name, pass, balance);
    }

    static Employee* login(int id, string password) {
        for (int i = 0; i < AllEmployees.size(); i++) {
            if (AllEmployees[i].getId() == id && AllEmployees[i].getPassword() == password) {

                return &AllEmployees[i];
            }
        }
        
        return nullptr;
    }
    static bool employeeOptions(Employee* employee) {
        int op;
        FilesManager x;
        printEmployeeMenu();
        cin >> op;
        while (op < 1 || op > 6) {
            cout << "Invalid option." << endl;
            cin >> op;
        }
        switch (op) {
        case 1:
            newClient(employee);
            x.updateClientsData();
            break;
        case 2:
            listAllClients(employee);
            break;
        case 3:
            searchForClient(employee);
            break;
        case 4:
            editClientInfo(employee);
            x.updateClientsData();
            break;
        case 5:
            return false; 
        default:
            cout << "Invalid option.\n";
            break;
        }
        return true;
    }
};


