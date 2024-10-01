#pragma once
#include <iostream>
using namespace std;

class Validation
{
public:

	static bool validationName(string name)
	{
		if ((name.size() < 5 || name.size() > 20)) {
			return false;
		}
		for (int i = 0; i < name.size(); i++)
		{
			if (!isalpha(name[i]) && name[i] != ' ')
			{
				return false;
			}
		}
		return true;
	}
	static bool validationPass(string password)
	{
		for (int i = 0; i < password.size(); i++)
		{
			if (password[i] == ' ')
			{
				return false;
			}
		}
		return(password.size() >= 8 && password.size() <= 20);
	}
	static bool validationBalance(double balance)
	{
		return(balance >= 1500);
	}
	static bool validationSalary(double Salary)
	{
		return(Salary >= 5000);
	}

};