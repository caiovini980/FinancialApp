#include "DataManager.hpp"

DataManager::DataManager(){}

void DataManager::AddToDatabase(Account& account)
{
    // open for writing
    std::fstream writingFile;
    writingFile.open("Accounts.txt", std::ios::app);

    std::cout << "Opening file for writing...\n";
    if (writingFile.is_open())
    {
        std::cout << "Updating account on the database...\n";
        std::string userData = account.GetAccountOwner() + " = " + std::to_string(account.GetAmountStored()) + "\n";
        std::cout << userData;

        writingFile << userData; 
    }      

    std::cout << "Closing file for writing...\n";
    writingFile.close();
}

Account* DataManager::CheckAccountOnDatabase(std::string& userName)
{
    // open for reading
    std::string line;
    std::fstream readingFile;
    readingFile.open("Accounts.txt", std::ios::in);

    std::cout << "Opening file for reading..."<< "\n";
    if (readingFile.is_open())
    {
        // check if have user saved
        while (std::getline(readingFile, line))
        {
            std::string auxName = line.substr(0, line.find(" = "));
            std::cout << "Line: " << line << "\n"; //<< "\nauxName: " << auxName;

            // if yes, return the saved user
            if (auxName == userName)
            {
                Account existingAccount;
                Account* pointerToAccount = &existingAccount;

                std::string amountInString = line.substr(line.find(" = ") + 3); // change to index to get the amount saved
                std::cout << "Amount saved: " << amountInString << "\n";
                float amountToAdd = std::stof(amountInString);

                existingAccount.SetupNewAccount(userName, amountToAdd);
                std::cout << "Found a account on file... Closing the file..."<< "\n";
                readingFile.close();
                return pointerToAccount;
            }
        }

        std::cout << "Closing file for reading..."<< "\n";
        readingFile.close();
        return NULL;
    }
}
