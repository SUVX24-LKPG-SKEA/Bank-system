#include "Bank.hpp"

/**
 * @param id takes in id of the bankAccount
 * @param info a pointer to the bankAccount which is allocated to the heap.
 */
void Bank::addAccount(int id, bankAccount* info) 
{
    std::lock_guard<std::mutex> lock(this->mapMtx);
    account[id] = info;
}

/**
 * @param id takes in id of the bankAccount
 * @returns A pointer to the account
 */
bankAccount* Bank::getAccount(int id) 
{
    std::lock_guard<std::mutex> lock(this->mapMtx);
    return account.at(id);
}

Bank::~Bank()
{
    std::lock_guard<std::mutex> lock(this->mapMtx);
    for (auto [key, value] : this->account)
    {
        delete value;
        value = nullptr;
    }
}

const std::map<int, bankAccount*> Bank::getAccounts() const noexcept 
{
    return this->account;
}

