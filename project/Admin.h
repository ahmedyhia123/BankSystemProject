#pragma once

#include "Employee.h"
#include <utility>

class Admin :public Employee
{
public:

	Admin(int id, string name, string password, double salary)
		: Employee(id, name, password, salary) {};
	Admin(string name, string password, double salary)
		: Employee(name, password, salary) {};



	//Methods

	void addEmployee(Employee& c) {
		AllEmployees.push_back(c);
	}

	pair<Employee*,bool> searchEmployee(int id) {
		for (int i = 0; i < AllEmployees.size(); i++) {
			if (AllEmployees[i].getId() == id) {
				return {&AllEmployees[i], true};
			}
		}

		return { nullptr,false };
	}
	void listEmployee() {
		if (AllEmployees.empty()) {
			cout << "No Employees Found !! \n";
			return;
		}

		for (int i = 0; i < AllEmployees.size(); i++) {
			AllEmployees[i].displayInfo();
			cout << endl << "----------------------------\n";
		}
	}
	void editEmployee(int id, string name, string password, double salary) {
		pair<Employee*,bool> employee = searchEmployee(id);
		if (employee.second) {
			employee.first->setName(name);
			employee.first->setPassword(password);
			employee.first->setSalary(salary);
			cout << "Employee Edited Successfully\n";
		}
		else {
			cout << "Employee with ID " << id << " not found.\n";
		}

	}

};

static vector<Admin> AllAdmins;