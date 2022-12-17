#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <string>
#include <cstdlib>
#include "../Accounts/Account.hpp"

class AccountManager
{
public:
    AccountManager();
    Account CreateNewAccount(std::string& userName);
    void AddAccountToDatabase(Account& account, std::fstream& file);
    void CheckSavedAccounts();

private:
    //Account accounts[10];
};

#endif // ACCOUNTMANAGER_H
