#pragma once
#include"Admin.h"
#include"Employee.h"

#include <vector>
#include"Client.h"

class DataSourceInterface {
public:
    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee) = 0;
    virtual void addAdmin(Admin) = 0;

    virtual void getAllClients() = 0;
    virtual void getAllEmployees() = 0;
    virtual void getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;

    virtual void updateClientsData() = 0;
    virtual void updateEmployeesData() = 0;
    virtual void updateAdminsData() = 0;
};