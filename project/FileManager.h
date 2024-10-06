#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include "Employee.h"

class FileManager : public DataSourceInterface
{
public:

	static void addClient(Client c) {
		FilesHelper::saveClient(c);
	}
	static void addEmployee(Employee e) {
		FilesHelper::saveEmployee("Employee.txt", "LastEmployeeId.txt", e);
	}

	static void addAdmin(Employee a) {
		FilesHelper::saveEmployee("Admin.txt", "LastAdminId.txt", a);
	}
	static void getAllClients() {
		FilesHelper::getClients();
	}
	static void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	static void getAllAdmins() {
		FilesHelper::getAdmins();
	}

	static void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "LastClientId.txt");
	}
	static void removeAllEmployees() {
		FilesHelper::clearFile("Employee.txt", "LastEmployeeId.txt");
	}
	static void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "LastAdminId.txt");
	}




};