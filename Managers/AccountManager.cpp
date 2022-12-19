#include "AccountManager.h"
#include <iostream>

AccountManager::AccountManager() {}

Account AccountManager::CreateNewAccount(std::string& userName)
{
    DataManager dataManager;
    Account* accountSaved = dataManager.CheckAccountOnDatabase(userName);
    
    if (accountSaved == nullptr)
    {
        std::cout << "Creating a new account for " << userName << "\n";
        system("pause");

        Account newAccount;
        newAccount.SetupNewAccount(userName);
        return newAccount;
    }

    std::cout << "Found an existing account saved!\n";
}

void AccountManager::CheckSavedAccounts()
{
    // just for test
}

void AccountManager::AddAccountToDatabase(Account& account, std::fstream& file)
{
    if (file.is_open())
    {
        std::cout << "Adding account to the database...\n";
        system("pause");

        file << account.GetAccountOwner() << " = " << account.GetAmountStored() << "\n\n";
    }
    else
    {
        std::cout << "ERROR to open data file!\n\n";
    }

    file.close();
    //this->CheckSavedAccounts();
}