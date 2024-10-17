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
		
		string NewPass = FillData::enterPassword();

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
		printClientMenu();
		cin >> op;
		while (op < 1 || op > 6) {
			cout << "Invalid option." << endl;
			cin >> op;
		}
		switch (op)
		{
		case 1:
			cout << "Balance : " << client->getBalance() << "EGP\n";
		case 2:
			cout << "Enter The Withdraw amount: \n";
			cin >> wd;
			client->withdraw(wd);
			fm.updateClientsData();
		case 3:
			cout << "Enter The Deposit amount : \n";
			cin >> dp;
			client->deposit(dp);
			fm.updateClientsData();
			
		case 4:
			cout << "Your Balance : " << client->getBalance() << endl << endl;
			cout << "Enter the recipient's id : \n";
			cin >> id;
			cout << "Enter the transfer amount : \n";
			cin >> to;
			client->transferTo(to ,*(x.searchClient(id)));
			fm.updateClientsData();
		case 5:
			updatePassword(client);
			fm.updateClientsData();
		case 6:
			return false; 
		default:
			cout << "Invalid option.\n";
			break;
		}
		return true;
	}
};

