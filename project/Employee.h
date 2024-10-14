#pragma once
#include "Person.h"
#include "Client.h"
#include <iostream>
#include<vector>
#include "Validation.h"
#include <utility>
using namespace std;

class Employee : public Person
{
private:
	double salary;
public:
	Employee() : salary(0) {};
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
	void addClient(Client& c) {
	
		AllClients.push_back(c);
	
	}

	 Client* searchClient(int id) {
		for (int i = 0; i < AllClients.size(); i++) {
			if (AllClients[i].getId() == id) {
				return  &AllClients[i] ;
			}
		}

		return  nullptr;
	}
	void listClient() {
		if (AllClients.empty()) {
			cout << "No Clients Found !! \n";
			return;
		}

		for (int i = 0; i < AllClients.size(); i++) {

			AllClients[i].displayInfo();
			cout << endl << "----------------------------\n";
		}
	}
	void editClient(int id, string name, string password, double balance) {
		Client* client = searchClient(id);
		if (client != nullptr) {
			client->setName(name);
			client->setPassword(password);
			client->setBalance(balance);
			cout << "Client Edited Successfully\n";
		}
		else {
			cout << "Client with ID " << id << " not found.\n";
		}
		
	}
	void displayInfo()
	{
		cout << "Employee Details:" << endl;
		Person::displayInfo();
		cout << "salary : " << salary << endl;
	}
};

static vector<Employee> AllEmployees;
