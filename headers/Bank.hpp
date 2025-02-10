#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>
#include <mutex>
#include "BankAccount.h"

/**
 * @brief Class for the bank, consisting of accounts and a mutex
 * 
 */
class Bank
{
private:
    // Ändrade från BankAccount till BankAccount* eftersom annars bygger inte programmet.
    std::map <int, BankAccount*> account;
    std::mutex mapMtx;
public:
    const std::map<int, BankAccount*> getAccounts() const noexcept;

    void addAccount(int id, BankAccount* info);
    BankAccount* getAccount(int id);
    ~Bank();
};

#endif