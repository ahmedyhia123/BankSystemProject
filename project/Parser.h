#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class Parser
{
public:

    //get all words of string after and before "-"
    static vector<string> split(const string line, char dash = '-') {
        vector<string> result;
        stringstream ss(line);
        string word;


        while (getline(ss, word, dash)) {
            result.push_back(word);
        }

        return result;
    }

    //get string line contain client date and return it as a client object

    static Client parseToClient(string line) {
        auto clientDate = split(line);

        //(int id, string name, string password, double balance)
        int id = stoi(clientDate[0]);
        string name = clientDate[1];
        string pass = clientDate[2];
        double balance = stod(clientDate[3]);

        return  Client(id, name, pass, balance);
    }

    //get string line contain Employee date and return it as a Employee object

    static Employee parseToEmployee(string line) {
        auto employeeDate = split(line);

        //(int id, string name, string password, double salary)
        int id = stoi(employeeDate[0]);
        string name = employeeDate[1];
        string pass = employeeDate[2];
        double salary = stod(employeeDate[3]);

        return  Employee(id, name, pass, salary);
    }

    //get string line contain Admin date and return it as an Admin object

    static Admin parseToAdmin(string line) {
        auto adminDate = split(line);

        //(int id, string name, string password, double balance)
        int id = stoi(adminDate[0]);
        string name = adminDate[1];
        string pass = adminDate[2];
        double salary = stod(adminDate[3]);

        return  Admin(id, name, pass, salary);
    }


};