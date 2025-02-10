#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>
#include <mutex>
#include "BankAccount.h"

class Bank
{
private:
    // Ändrade från bankAccount till bankAccount* eftersom annars bygger inte programmet.
    std::map <int, bankAccount*> account;
    std::mutex mapMtx;
public:
    const std::map<int, bankAccount*> getAccounts() const noexcept;

    void addAccount(int id, bankAccount* info);
    bankAccount* getAccount(int id);
    ~Bank();
};

#endif