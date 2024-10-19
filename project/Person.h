#pragma once
#include <iostream>
#include <vector>

#include <string>
#include "Validation.h"

using namespace std;

class Person {
protected:
	string name, password;
	int id;
public:
	Person() :id(0) {};
	Person(int id, string name, string password) : id(id) {

		if (Validation::validationName(name)) {
			this->name = name;
		}

		if (Validation::validationPass(password)) {
			this->password = password;
		};
	};
	Person(string name, string password) {

		if (Validation::validationName(name)) {
			this->name = name;
		}

		if (Validation::validationPass(password)) {
			this->password = password;
		}
	};

	//Setter
	void setName(string name)
	{
		while (!Validation::validationName(name)) {
			getline(cin, name);
		}
		this->name = name;
	}

	void setPassword(string password)
	{
		while (!Validation::validationPass(password)) {
			
			cin >> password;
		}
		this->password = password;
	}

	//Getter
	string getName()
	{
		return name;
	}
	string getPassword()
	{
		return password;
	}
	int getId()
	{
		return id;
	}
	virtual void displayInfo()    //virtual impure
	{
		cout << "Name : " << name << endl
			<< "Password : " << password << endl
			<< "Id : " << id << endl;
	}
};