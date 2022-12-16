//
//  Account.hpp
//  FinancialApp
//
//  Created by Caio Aguiar on 29/11/22.
//

#ifndef Account_hpp
#define Account_hpp

#include <string>
#include <fstream> // handle files
#include <cstdlib> // error handling

class Account 
{
public:
    Account();
    void SetupNewAccount(std::string& userName);
    void SetupNewAccount(std::string& userName, float amountToStore);
    void AddMoney(float amountToAdd);
    float GetAmountStored();
    std::string GetAccountOwner();
    
private:
    std::string accountName;
    float amountStored;
};

#endif /* Account_hpp */
