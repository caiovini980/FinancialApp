#include "DataManager.hpp"

DataManager::DataManager(){}

void DataManager::AddToDatabase(Account& account)
{
    std::fstream dataFile("Accounts.txt", std::ios_base::in | std::ios_base::out);
    dataFile.open("Accounts.txt");

    std::cout << "Opening file..."<< "\n";
    if (dataFile.is_open())
    {
        std::cout << "Adding account to the database...\n";
        std::string userData = account.GetAccountOwner() + " = " + std::to_string(account.GetAmountStored()) + "\n";
        std::cout << userData;

        dataFile << userData;
        //dataFile.write(userData, std::strlen(userData));
    }
    else
    {
        std::cout << "ERROR to open data file!\n\n";
    }

    std::cout << "\nClosing file..." << "\n";
    dataFile.close();
    system("pause");
}

Account DataManager::CheckAccountOnDatabase(Account& account)
{
    // create a file to save account data
    /*if (dataFile.is_open())
    std::fstream dataFile("Accounts.txt", std::fstream::app);
    dataFile.open("Accounts.txt");

    // check if already have this accoun t saved on the file
    // if yes, use this account
    // if not, create a new one
    std::string line;
    std::cout << "Trying to open the data file!\n";
    if (dataFile.is_open())
    {
        std::cout << "Is Open!\n";
        while (std::getline(dataFile, line))
        {
            // generate the first substring based on the position of the delimiter, in this case: "="
            std::string auxName = line.substr(0, line.find(" = "));

            std::cout << "Line: " << line << "\n"; //<< "\nauxName: " << auxName;

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

        std::cout << "Can't find " << userName << " on the database, closing the file...\n";
        dataFile.close();
    }*/
}
