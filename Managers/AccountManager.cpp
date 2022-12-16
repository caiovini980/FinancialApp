#include "AccountManager.h"
#include <iostream>

AccountManager::AccountManager() {}

Account AccountManager::CreateNewAccount(std::string& userName)
{
    // create a file to save account data
    std::fstream dataFile;
    dataFile.open("Accounts.txt");

    // check if already have this account saved on the file
    // if yes, use this account
    // if not, create a new one
    std::string line;
    if (dataFile.is_open())
    {
        while (std::getline(dataFile, line))
        {
            // generate the first substring based on the position of the delimiter, in this case: "="
            std::string auxName = line.substr(0, line.find(" = ")); 
            if (auxName == userName)
            {
                Account existingAccount;
                std::string amountInString = line.substr(1, line.find(" = "));
                float amountToAdd = std::stof(amountInString);

                existingAccount.SetupNewAccount(userName, amountToAdd);
                dataFile.close();
                return existingAccount;
            }
        }
    }

    std::cout << "Creating a new account for " << userName << "\n";
    Account newAccount;

    newAccount.SetupNewAccount(userName);
    this->AddAccountToDatabase(newAccount, dataFile);
    return newAccount;
}

void AccountManager::CheckSavedAccounts()
{

}

void AccountManager::AddAccountToDatabase(Account& account, std::fstream& file)
{
    if (file.is_open())
    {
        file << account.GetAccountOwner() << " = " << account.GetAmountStored() << "\n\n";
        file.close();
    }
    else
    {
        std::cout << "ERROR!\n\n";
    }

    //this->CheckSavedAccounts();
}