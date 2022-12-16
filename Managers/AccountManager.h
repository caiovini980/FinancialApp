#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <string>
#include <fstream>
#include <cstdlib>
#include "../Accounts/Account.hpp"

class AccountManager
{
public:
    AccountManager();
    Account CreateNewAccount(std::string& userName);
    void CheckSavedAccounts();
private:
    //Account accounts[10];
    void AddAccountToDatabase(Account& account, std::fstream& file);
};

#endif // ACCOUNTMANAGER_H
