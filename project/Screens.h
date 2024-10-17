#pragma once
#include<iostream>
#include <windows.h>
#include"AdminManager.h"
#include "EmployeeManager.h"
#include"ClientManger.h"

using namespace std;

class Screens
{

public:

	static void bankName() {

		cout << "\t\t\t\t\t@@@@@    @@@@@   @@   @@  @@  @@ \n";
		cout << "\t\t\t\t\t@@   @  @@   @@  @@@  @@  @@ @   \n";
		cout << "\t\t\t\t\t@@@@@   @@@@@@@  @@ @ @@  @@@    \n";
		cout << "\t\t\t\t\t@@   @  @@   @@  @@  @@@  @@ @   \n";
		cout << "\t\t\t\t\t@@@@@   @@   @@  @@   @@  @@  @@ \n";

}

	static void welcome() {
		system("Color 0e");
		cout << "\n\n\n\n\n\n";
		cout << "\t    @@       @@  @@@@@@@  @@      @@@@@@@  @@@@@@@@  @@@@    @@@@  @@@@@@@     @@@@@@@@  @@@@@@@@\n";
		cout << "\t    @@   @   @@  @@       @@      @@       @@    @@  @@  @  @  @@  @@		  @@	 @@    @@\n";
		cout << "\t    @@  @@@  @@  @@@@@@   @@      @@       @@    @@  @@   @@   @@  @@@@@@	  @@     @@    @@\n";
		cout << "\t    @@ @@ @@ @@  @@       @@      @@       @@    @@  @@        @@  @@             @@     @@    @@\n";
		cout << "\t    @@@     @@@  @@@@@@@  @@@@@@  @@@@@@@  @@@@@@@@  @@        @@  @@@@@@@        @@     @@@@@@@@\n\n\n";
		bankName();
		Sleep(6000);
		system("cls");
		system("Color 3e");
	}


	static void loginOptions() {
		cout << "\t\t\t\tLogin As \n\n";
		cout << "1- Admin " << endl
			<< "2- Employee " << endl
			<< "3- Client " << endl;
	}
	static int loginAs() {
		loginOptions();
		int op;
		cin >> op;
		while (op < 1 || op > 3) {
			cout << "Invalid option." << endl;
			cin >> op;
		}
		switch (op)
		{
		case 1:
			return 1;
		case 2 :
			return 2;
		case 3:
			return 3;
		}
		return 0;
	}

	static void logout() {
		cout << "Loging Out......\n";
		loginScreen(loginAs());
	}
	static void loginScreen(int c) {
		int id;
		string pass;
		bool loginSuccessful = false;

		while (!loginSuccessful) {
			cout << "Enter Your ID: \n";
			cin >> id;
			cout << "Enter Your Password: \n";
			cin >> pass;

			switch (c) {
			case 1: {
				Admin* admin = AdminManager::login(id, pass);
				if (admin) {
					loginSuccessful = true;
					while (AdminManager::AdminOptions(admin)) {}
					logout();
				}
				else {
					cout << "Invalid Admin Password or ID. Please try again.\n";
				}
				break;
			}
			case 2: {
				Employee* employee = EmployeeManager::login(id, pass);
				if (employee) {
					loginSuccessful = true;
					while (EmployeeManager::employeeOptions(employee)) {}
					logout();
				}
				else {
					cout << "Invalid Employee Password or ID. Please try again.\n";
				}
				break;
			}
			case 3: {
				Client* client = ClientManger::login(id, pass);
				if (client) {
					loginSuccessful = true;
					while (ClientManger::clientOptions(client)) {}
					logout();
				}
				else {
					cout << "Invalid Client Password or ID. Please try again.\n";
				}
				break;
			}
			default:
				cout << "Invalid option.\n";
				return;
			}

		}
	}

	static void runApp() {
		FilesManager fm;
		fm.getAllData();
		welcome();
		loginScreen(loginAs());
		fm.removeAllData();
	}


};

