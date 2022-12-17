#include "AccountManager.h"
#include <iostream>

AccountManager::AccountManager() {}

Account AccountManager::CreateNewAccount(std::string& userName)
{
    std::cout << "Creating a new account for " << userName << "\n";
    system("pause");

    //this->AddAccountToDatabase(newAccount, dataFile);
    Account newAccount;

    newAccount.SetupNewAccount(userName);
    return newAccount;
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