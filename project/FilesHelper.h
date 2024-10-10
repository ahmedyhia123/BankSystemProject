#pragma once
#include <iostream>
#include "Parser.h"

#include "Client.h"
#include "Employee.h"
#include <fstream>

#include <string>
#include <sstream>


using namespace std;

class FilesHelper
{
public:

	//Save last object id
	static void saveLast(string path, int id) {
		ofstream lastId(path);

		if (lastId.is_open()) {
			lastId << id;
			lastId.close();
		}
		else {
			cout << "cant open file\n";
		}
	}

	//return last object  id
	static int getLast(string path) {
		ifstream lastId(path);
		int id;
		lastId >> id;
		lastId.close();
		return id;
	}
	static void saveClient(Client c) {
		ofstream saveClient("Clients.txt", ios::app);
		if (saveClient.is_open()) {
			int id = getLast("LastClientId.txt") + 1;
			saveClient << id << "-" << c.getName() << "-" << c.getPassword() << "-" << c.getBalance() << endl;
			saveLast("LastClientId.txt", id);
			saveClient.close();
		}
		else {
			cout << "Can't open file\n";
		}
	}

	static void saveEmployee( Employee e) {

		ofstream saveEmployee("Employee.txt", ios::app);
		if (saveEmployee.is_open()) {
			int id = getLast("LastEmployeeId.txt") + 1;
			saveEmployee << id << "-" << e.getName() << "-" << e.getPassword() << "-" << e.getSalary() << endl;
			saveLast("LastEmployeeId.txt", id);
			saveEmployee.close();
		}
		else {
			cout << "Can't open file\n";
		}
	}
	static void saveAdmin(Admin e) {

		ofstream saveAdmin("Admin.txt", ios::app);
		if (saveAdmin.is_open()) {
			int id = getLast("LastAdminId.txt") + 1;
			saveAdmin << id << "-" << e.getName() << "-" << e.getPassword() << "-" << e.getSalary() << endl;
			saveLast("LastAdminId.txt", id);
			saveAdmin.close();
		}
		else {
			cout << "Can't open file\n";
		}


	}

	static void getClients() {
		ifstream ClientsData("Clients.txt");
		if (ClientsData.is_open()) {
			string line;
			while (getline(ClientsData, line)) {
				auto a = Parser::parseToClient(line);
				AllClients.push_back(a);
			}
		}
		else {
			cout << "Can't open file\n";
		}
		ClientsData.close();
	}

	static void getEmployees() {
		ifstream EmployeesData("Employee.txt");
		if (EmployeesData.is_open()) {
			string line;
			while (getline(EmployeesData, line)) {
				auto a = Parser::parseToEmployee(line);
				AllEmployees.push_back(a);
			}
		}
		else {
			cout << "Can't open file\n";
		}
		EmployeesData.close();
	}

	static void getAdmins() {
		ifstream AdminsData("Admins.txt");
		if (AdminsData.is_open()) {
			string line;
			while (getline(AdminsData, line)) {
				auto a = Parser::parseToAdmin(line);
				AllAdmins.push_back(a);
			}
		}
		else {
			cout << "Can't open file\n";
		}
		AdminsData.close();
	}

	static void clearFile(string fileName, string lastIdFile) {


		ofstream file(fileName, ios::trunc);
		if (file.is_open()) {

			file.close();
		}
		else {
			cout << "Can't open the file to clear contents.\n";
		}

		saveLast(lastIdFile, 0);

	}

};