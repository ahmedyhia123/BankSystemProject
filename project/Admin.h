#pragma once

#include "Employee.h"
#include <utility>


class Admin :public Employee
{
public:

	Admin(int id, string name, string password, double salary)
		: Employee(id, name, password, salary) {};
	Admin(string name, string password, double salary)
		: Employee(name, password, salary) {
		
	
	
	};



	//Methods

	void addEmployee(Employee& c) {
		

		AllEmployees.push_back(c);
		
	}

	Employee* searchEmployee(int id) {
		for (int i = 0; i < AllEmployees.size(); i++) {
			if (AllEmployees[i].getId() == id) {
				return &AllEmployees[i];
			}
		}

		return  nullptr;
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
		

		Employee* employee = searchEmployee(id);
		if (employee != nullptr) {
			employee->setName(name);
			employee->setPassword(password);
			employee->setSalary(salary);
			cout << "Employee Edited Successfully\n";
		}
		else {
			cout << "Employee with ID " << id << " not found.\n";
		}
		

	}

};

static vector<Admin> AllAdmins;