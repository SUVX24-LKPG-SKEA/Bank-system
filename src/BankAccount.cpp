#include "BankAccount.h"
#include <iostream>

bankAccount::bankAccount(int balance, int accountNumber)
{
    std::lock_guard<std::mutex> lock(this->balanceMtx);
    this->balance = balance;
    this->accountNumber = accountNumber;
}

bankAccount::bankAccount(int accountNumber)
{
    std::lock_guard<std::mutex> lock(this->balanceMtx);
    this->balance = 0;
    this->accountNumber = accountNumber;
}

/**
 * @throws When amount is negative or zero
 */
void bankAccount::deposit(int amount)
{
    std::lock_guard<std::mutex> lock(this->balanceMtx);
    if(amount <= 0)
    {
        throw "Invalid amount";
    }
    deposits += amount;
    balance += amount;

}

/**
 * @throws When amount is negative or zero
 */
void bankAccount::withdraw(int amount)
{
    std::lock_guard<std::mutex> lock(this->balanceMtx);
    if (amount > balance)
    {
        throw "Insufficient funds";
    }
    else if(amount <= 0)
    {
        throw "Invalid amount";
    }

    withdraws += amount;
    balance -= amount;
}

int bankAccount::getBalance()
{
    std::lock_guard<std::mutex> lock(this->balanceMtx);
    return balance;
}

int bankAccount::getWithdraws() 
{
    std::lock_guard<std::mutex> lock(this->balanceMtx);
    return withdraws;
}

int bankAccount::getDeposits() 
{
    std::lock_guard<std::mutex> lock(this->balanceMtx);
    return deposits;
}

int bankAccount::getId() 
{
    return this->accountNumber;
}