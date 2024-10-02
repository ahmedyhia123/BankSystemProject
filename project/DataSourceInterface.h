#pragma once
#include"Admin.h"
#include"Client.h"

class DataSourceInterface {
public:
    virtual void addClient(const Client& client) = 0;
    virtual void addEmployee(const Employee& employee) = 0;
    virtual void addAdmin(const Admin& admin) = 0;

    virtual void  getAllClients() = 0;
    virtual void getAllEmployees() = 0;
    virtual void getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};