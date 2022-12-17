//
//  Account.cpp
//  FinancialApp
//
//  Created by Caio Aguiar on 29/11/22.
//

#include "Account.hpp"
#include <iostream>

Account::Account() {}

void Account::SetupNewAccount(std::string& userName)
{
    // initialize variables
    accountName = userName;
    amountStored = 0.0f;
}

void Account::SetupNewAccount(std::string& userName, float amountToStore)
{
    // initialize variables
    accountName = userName;
    amountStored = amountToStore;
}

void Account::AddMoney(float amountToAdd)
{
    //std::cout << "Amount stored: " << amountStored << " - Amount to add: " << amountToAdd << "\n";
    
    amountStored += amountToAdd;
    std::cout << "\nAmount added successfully\n";
    std::cout << "New amount stored is R$" << amountStored << "\n\n";
}

float Account::GetAmountStored()
{
    return amountStored;
}

std::string Account::GetAccountOwner()
{
    return accountName;
}
