#pragma once
#include "DataSourceInterface.h"
class FilesManager : public DataSourceInterface
{
public:
	void addClient(Client c) {
		FilesHelper::saveClient(c);
	}
	void addEmployee(Employee e) {
		FilesHelper::saveEmployee(e);
	}

	void addAdmin(Admin a) {
		FilesHelper::saveAdmin(a);
	}
	void getAllClients() {
		FilesHelper::getClients();
	}
	void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	void getAllData() {
		getAllAdmins();
		getAllEmployees();
		getAllClients();
	}

	void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "LastClientId.txt");
	}
	void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "LastEmployeeId.txt");
	}
	void removeAllAdmins() {
		FilesHelper::clearFile("Admins.txt", "LastAdminId.txt");
	}

	void updateClientsData() {
		removeAllClients();

		for (int i = 0; i <  AllClients.size(); i++) {

			addClient(AllClients[i]);

		}
	}
	void updateEmployeesData() {
		removeAllEmployees();

		for (int i = 0; i < AllEmployees.size(); i++) {

			addEmployee(AllEmployees[i]);
		}
	}
	void updateAdminsData() {
		removeAllAdmins();

		for (int i = 0; i < AllAdmins.size(); i++) {

			addAdmin(AllAdmins[i]);

		}
	}
	
	void removeAllData() {
		removeAllClients();
		removeAllAdmins();
		removeAllEmployees();
	}

};

