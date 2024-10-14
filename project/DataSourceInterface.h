#pragma once
#include "Client.h"
#include "Admin.h"
#include "FilesHelper.h"

class DataSourceInterface
{


    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee ) = 0;
    virtual void addAdmin(Admin ) = 0;

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
