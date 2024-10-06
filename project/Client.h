#pragma once
#include "Person.h"
#include <string>

#include "Validation.h"
class Client :public Person
{
private:
	double balance;
public:
	Client() :balance(0) {};
	Client(int id, string name, string password, double balance)
		: Person(id, name, password) {
		if (Validation::validationBalance(balance)) {
			this->balance = balance;
		}
		else {
			this->balance = 0;
		}

	};
	Client(string name, string password, double balance)
		: Person(name, password) {
		if (Validation::validationBalance(balance)) {
			this->balance = balance;
		}
		else {
			this->balance = 0;
		}

	};


	//Setter
	void setBalance(double firstDeposit) {
		while (firstDeposit < 1500)
		{
			cout << "First deposit must be at least 1500 to create an account!" << endl;
			cout << "Please enter first deposit: ";
			cin >> firstDeposit;
		}

		this->balance = firstDeposit;

	}
	double getBalance() {
		return balance;
	}


	//Method
	void deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
		}
		else
		{
			cout << "Error!\n";
		}
	}
	void withdraw(double amount)
	{
		if (amount <= balance && amount > 0) {

			balance -= amount;
		}
		else
		{
			cout << "you don't have this balance !\n";
		}
	}
	void transferTo(double amount, Client& recipient)
	{
		if (amount <= balance && amount > 0)
		{
			withdraw(amount);
			recipient.deposit(amount);
		}
		else
		{
			cout << " The balance is not enough !\n";
		}
	}
	void checkBalance()
	{
		cout << "Current balance : " << balance << endl;
	}
	void displayInfo()
	{
		cout << "Client Details:" << endl;
		Person::displayInfo();
		cout << "Balance : " << balance << endl;
	}




};


static vector<Client> AllClients;