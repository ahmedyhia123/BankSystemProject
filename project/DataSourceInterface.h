#pragma once
#include"Admin.h"
#include"Employee.h"

#include <vector>
#include"Client.h"

class DataSourceInterface {
public:
    virtual void addClient() = 0;
    virtual void addEmployee() = 0;
    virtual void addAdmin() = 0;

    virtual void  getAllClients() = 0;
    virtual void getAllEmployees() = 0;
    virtual void getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};