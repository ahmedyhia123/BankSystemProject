#pragma once
#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "FillData.h"
#include"Employee.h"
#include "FilesManager.h"

using namespace std;

class ClientManger
{
public:
	static void printClientMenu() {
		cout << "1- Show Balance.\n"
			<< "2- Withdraw. \n"
			<< "3- Deposit.\n"
			<< "4- Transfer.\n"
			<< "5- Edit Password.\n"
			<< "6- Logout.\n";
}
	static void updatePassword(Person* p) {
		FilesManager x;
		
		string NewPass;

		cout << "Enter The New Password : \n";
		cin >> NewPass;
		while (!Validation::validationPass(NewPass)) {
			cout << "Please Enter Valid Password : \n";
			cin >> NewPass;
		}

		p->setPassword(NewPass);
		
		cout << "Password Updated successfully \n";
		x.updateClientsData();
	}


	static Client* login(int id, string password) {
		for (int i = 0; i < AllClients.size(); i++) {
			if (AllClients[i].getId() == id && AllClients[i].getPassword() == password) {

				return &AllClients[i];
			}
		}
		
		return nullptr;
	}

	static bool clientOptions(Client* client) {
		int op, wd,dp,id;
		double to;
		Employee x;
		FilesManager fm;
		bool is_done = true;
		printClientMenu();
		cin >> op;
		while (op < 1 || op > 6) {
			cout << "Invalid option." << endl;
			cin >> op;
		}
		switch (op)
		{
		case 1:
			system("cls");
			cout << "Balance : " << client->getBalance() << "EGP\n";
			break;
		case 2:
			system("cls");
			cout << "Enter The Withdraw amount: \n";
			cin >> wd;
			client->withdraw(wd);
			fm.updateClientsData();
			break;
		case 3:
			system("cls");
			cout << "Enter The Deposit amount : \n";
			cin >> dp;
			client->deposit(dp);
			fm.updateClientsData();
			break;
		case 4:
			system("cls");
			cout << "Your Balance : " << client->getBalance() << endl << endl;
			cout << "Enter the recipient's id : \n";
			cin >> id;
			cout << "Enter the transfer amount : \n";
			cin >> to;
			is_done = client->transferTo(to ,*(x.searchClient(id)));
			if (is_done) {
				cout << "Successful transaction ";
			fm.updateClientsData();
			}
			else {
				cout << "You Don't have enough money ! \n";
			}
			break;
		case 5:
			system("cls");
			updatePassword(client);
			fm.updateClientsData();
			break;
		case 6:
			system("cls");
			return false; 
		default:
			cout << "Invalid option.\n";
			break;
		}
		return true;
	}
};

