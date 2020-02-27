#include <iostream>
#include "Account.hpp"

Account::Account(std::string accName,
                std::string accNumber,
                int accType,
                float accBalance)
{
    accountName = accName;
    accountNumber = accNumber;
    accountType = accType;
    accountBalance = accBalance;
}

std::string Account::getAccountNumber() const
{
    return accountNumber;
}

float Account::getBalance() const 
{
    printDetail();
    return accountBalance;
}

void Account::withdraw(float amount)
{
    accountBalance -= amount;
    printDetail();
    std::cout << amount << " withdrawn!\n";
}

void Account::deposit(float amount)
{
    accountBalance += amount;
    printDetail();
    std::cout << amount << " deposited!\n";
}

void Account::transfer(float amount, Account &toAccount)
{
    std::cout << "\n>>> ";
    if (accountNumber == toAccount.accountNumber)
    {
        std::cout << "Failed to transfer RM" << amount << " from ";
        std::cout << accountNumber << " to " << toAccount.accountNumber << "! ";
        std::cout << "Cannot transfer into self!\n";
        return;
    }
    if (accountBalance < amount)
    {
        std::cout << "Failed to transfer RM" << amount << " from ";
        std::cout << accountNumber << " to " << toAccount.accountNumber << "! ";
        std::cout << "Insufficient funds!\n";
        return;
    }
    accountBalance -= amount;
    toAccount.accountBalance += amount;
    std::cout << "Successfully transfered RM" << amount << " from ";
    std::cout << accountNumber << " to " << toAccount.accountNumber << "! ";
}

void Account::printDetail() const
{
    std::cout <<"\n----------------------------------\n";
    std::cout << "Account name: " << accountName << "\n";
    std::cout << "Account number: " << accountNumber << "\n";
    std::cout << "Account type: ";
    switch(accountType)
    {
    case (int) AccountType::savings:
        std::cout << "Savings";
        break;

    case (int) AccountType::current:
        std::cout << "Current";
        break;
    }
    std::cout << "\n";
    std::cout << "Account balance: RM" << accountBalance;
    std::cout << "\n----------------------------------\n";
}
