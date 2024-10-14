#pragma once
#include"Validation.h"
class FillData
{
public:
	static string enterName()
	{
		string name;
		cout << "Please Enter Client Name : \n";
		cin >> name;
		while (!Validation::validationName(name))
		{
			cout << "Name is not valid\n";
			cout << "Name must be alphabetic from 5 to 20 Character\n";
			cout << "\nPlease Enter a Valid Name \n";
			cin >> name;
		}
		return name;
	}
	static string enterPassword()
	{
		string password;
		cout << "Please Enter Client Password : \n";
		cin >> password;
		while (!Validation::validationPass(password))
		{
			cout << "Password is not valid\n";
			cout << "Password must be alphabetic from 5 to 20 Character without space\n";
			cout << "\nPlease Enter a Valid Password \n";
			cin >> password;
		}
		return password;
	}
	static double enterBalance()
	{
		double balance;
		cout << "Please Enter Your Balance..... \n";
		cin >> balance;
		while (!Validation::validationBalance(balance))
		{
			cout << "Balance is not valid\n";
			cout << "Minimum Balance is 1500 L.E\n";
			cout << "\nPlease Enter a Valid Balance \n";
			cin >> balance;
		}
		return balance;
	}
	static double enterSalary()
	{
		double salary;
		cout << "Please Enter Your Salary..... \n";
		cin >> salary;
		while (!Validation::validationSalary(salary))
		{
			cout << "Salary is not valid\n";
			cout << "Minimum Salary is 5000 L.E\n";
			cout << "\nPlease Enter a Valid Salary \n";
			cin >> salary;
		}
		return salary;
	}
};