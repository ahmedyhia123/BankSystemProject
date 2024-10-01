#pragma once

#include "Employee.h"

class Admin :public Employee
{
public:
	
	Admin(int id, string name, string password, double salary)
		: Employee(id, name, password, salary) {};
	Admin(string name, string password, double salary)
		: Employee(name, password, salary) {};

	
};

static vector<Admin> AllAdmins;