
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "FilesHelper.h"
#include "FileManager.h"




using namespace std;

int main()
{
	FileManager::removeAllAdmins();
	FileManager::removeAllClients();
	FileManager::removeAllEmployees();
	

}
