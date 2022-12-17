#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "../Accounts/Account.hpp"

class DataManager
{
public:
	DataManager();
	void AddToDatabase(Account& account);
	Account CheckAccountOnDatabase(Account& account);

private:

};

#endif