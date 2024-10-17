#pragma once
#include <iostream>
#include "Parser.h"





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
		ofstream saveClient;
		saveClient.open("Clients.txt", ios::app);

		int id = getLast("LastClientId.txt") + 1;
		saveClient << id << "-" << c.getName() << "-" << c.getPassword() << "-" << c.getBalance() << endl;
		saveLast("LastClientId.txt", id);
		saveClient.close();
	}
	
	

	static void saveEmployee( Employee e) {

		ofstream saveEmployee;
		saveEmployee.open("Employees.txt", ios::app);
			int id = getLast("LastEmployeeId.txt") + 1;
			saveEmployee << id << "-" << e.getName() << "-" << e.getPassword() << "-" << e.getSalary() << endl;
			saveLast("LastEmployeeId.txt", id);
			saveEmployee.close();
		
	}
	static void saveAdmin(Admin e) {

		ofstream saveAdmin;
		saveAdmin.open("Admins.txt", ios::app);
			int id = getLast("LastAdminId.txt") + 1;
			saveAdmin << id << "-" << e.getName() << "-" << e.getPassword() << "-" << e.getSalary() << endl;
			FilesHelper::saveLast("LastAdminId.txt", id);
			saveAdmin.close();

	}

	static void getClients() {
		ifstream ClientsData;
		ClientsData.open("Clients.txt");
		string line;
		while (getline(ClientsData, line)) {
			auto a = Parser::parseToClient(line);
			AllClients.push_back(a);
		}	
		ClientsData.close();
	}

	static void getEmployees() {
		ifstream EmployeesData;
		EmployeesData.open("Employees.txt");
			string line;
			while (getline(EmployeesData, line)) {
				auto a = Parser::parseToEmployee(line);
				AllEmployees.push_back(a);
			}
		
		
		EmployeesData.close();
	}

	static void getAdmins() {
		ifstream AdminsData;
		AdminsData.open("Admins.txt");
			string line;
			while (getline(AdminsData, line)) {
				auto a = Parser::parseToAdmin(line);
				AllAdmins.push_back(a);
			}
		
		
		AdminsData.close();
	}

	static void clearFile(string fileName, string lastIdFile) {


		ofstream file;
		file.open(fileName, ios::trunc);

		file.close();
		
		
		saveLast(lastIdFile, 0);

	}

};