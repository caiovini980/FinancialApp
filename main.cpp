//
//  main.cpp
//  FinancialApp
//
//  Created by Caio Aguiar on 16/10/22.
//

#include <iostream>
#include <string>
#include <thread>
#include "Managers/AccountManager.h"
#include "Managers/DataManager.hpp"

void ExecuteOperation(Account& account, std::string& username, float choice)
{
    if (choice == 1)
    {
        // ask for amount to add
        float amountToAdd;
        std::cout << "How much you wish to add? ";
        std::cin >> amountToAdd;
        account.AddMoney(amountToAdd);
    }
    
    if (choice == 2)
    {
        float amountStored = account.GetAmountStored();
        std::cout << username << " have R$" << amountStored << " stored.\n\n";
    }
}

void GetChoice(std::string& name, int& choice)
{
    system("cls");
    
    std::cout << "Great to have you here " << name << ", how can I help you?\n";
    std::cout << "1 - Add money to my account.\n";
    std::cout << "2 - Check how much I have.\n";
    std::cout << "3 - Quit application.\n";
    std::cin >> choice;
    
    system("cls");
}

void CloseApp(DataManager& dataManager, Account& userAccount)
{
    std::cout << "Saving data...\n";
    //accountManager.AddAccountToDatabase(userAccount);
    dataManager.AddToDatabase(userAccount);
    std::cout << "Exiting FinancialApp...\n";
}

int main(int argc, const char * argv[])
{
    std::string _name = "";
    int _choice = 0;
    
    std::cout << "Hello and welcome to the FinancialApp, made in C++!\n";
    std::cout << "To get started, what's your name?\n";
    std::cin >> _name;
    
    AccountManager accountManager;
    DataManager dataManager;
    Account userAccount = accountManager.CreateNewAccount(_name);
    
    // execute loop
    while (_choice != 3)
    {
        std::cout << "Entering loop...\n";
        GetChoice(_name, _choice);
        ExecuteOperation(userAccount, _name, _choice);
        system("pause");
    }

    //std::thread closeThread(CloseApp, dataManager, userAccount);
    //closeThread.join();
    CloseApp(dataManager, userAccount);
    return 0;
}
