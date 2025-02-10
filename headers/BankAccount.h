#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <mutex>
#include <atomic>

class bankAccount {
private: 
    int balance; 
    int deposits = 0;
    int withdraws = 0;
    int accountNumber;

    std::mutex balanceMtx;
public: 
    bankAccount(int balance, int accountNumber);
    bankAccount(int accountNumber);
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
    int getWithdraws();
    int getDeposits();
    int getId();
};

#endif