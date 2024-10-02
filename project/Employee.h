#pragma once
#include "Person.h"

#include "Validation.h"
class Employee : public Person
{
private:
	double salary;
public:
	Employee(): salary(0) {};
	Employee(int id, string name, string password, double salary)
		: Person(id, name, password) {
		if (Validation::validationSalary(salary)) {
			this->salary = salary;
		}
		else {
			this->salary = 0;
		}
	};

	Employee(string name, string password, double salary)
		: Person(name, password) {
		if (Validation::validationSalary(salary)) {
			this->salary = salary;
		}
		else {
			this->salary = 0;
		}
	};

	//Setter
	void setSalary(double  salary)
	{
		while (!Validation::validationSalary(salary)) {
			cout << "Min Salary 5000" << endl;
			cin >> salary;
		}
		this->salary = salary;
	}
	//Getter
	double getSalary()
	{
		return salary;
	}
	void displayInfo()
	{
		cout << "Employee Details:" << endl;
		Person::displayInfo();
		cout << "salary : " << salary << endl;
	}
};

static vector<Employee> AllEmployees;