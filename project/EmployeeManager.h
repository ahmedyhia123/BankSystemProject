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
        cout << "Enter The New Client Name : \n";
        cin.ignore();
        getline(cin, name);
        while (!Validation::validationName(name)) {
            cout << "Please Enter Valid Name : \n";
            getline(cin, name);
        }
        cout << "Enter The New Client Password : \n";
        cin >> pass;
        while (!Validation::validationPass(pass)) {
            cout << "Please Enter Valid Password : \n";
            cin >> pass;
        }
        cout << "Enter The New Client First Deposit : \n";
        cin >> balance;
        while (!Validation::validationBalance(balance)) {
            cout << "Please Enter Valid deposit : (Min: 1500 L.E)\n";
            cin >> balance;
        }
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
        int id,op;
        cout << "Please Enter Client ID : \n";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client == nullptr) {
            cout << "Client Not Founded!\n";
            return;
        }

        cout << "1- Name." << endl
            << "2- Password." << endl;
        cout << "What do you want to Edit : \n";
        cin >> op;
        while (op < 1 || op > 2) {
            cout << "Invalid option." << endl;
            cin >> op;
        }
        
        switch (op)
        {
        case 1:
            cout << "Enter The New Name : \n";
            getline(cin, name);
            while (Validation::validationName(name)) {
                cout << "Please Enter Valid Name : \n";
                getline(cin, name);
            }

            client->setName(name);
            break;
        case 2:
            cout << "Enter The New Password : \n";
            cin >> pass;
            while (Validation::validationPass(pass)) {
                cout << "Please Enter Valid Password : \n";
                getline(cin, pass);
            }
            client->setPassword(pass);
            break;
        default:
            break;
        }
        
        
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
            system("cls");
            newClient(employee);
            x.updateClientsData();
            break;
        case 2:
            system("cls");
            listAllClients(employee);
            break;
        case 3:
            system("cls");
            searchForClient(employee);
            break;
        case 4:
            system("cls");
            editClientInfo(employee);
            x.updateClientsData();
            break;
        case 5:
            system("cls");
            return false; 
        default:
            cout << "Invalid option.\n";
            break;
        }
        return true;
    }
};


