#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <mutex>

#include "Bank.hpp"
#include "BankAccount.h"
#include "Logger.hpp"

std::mutex mtx, printMtx;

/**
 * Randomizes deposits and withdrawals and generates random account numbers to perform operations on.
 * @param bank The bank object
 * @param clientid The id of the client
 * @param iterations The number of operations to perform
 */
void client(Bank& bank, const int clientid, const int iterations)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution accountDist(1000, 1004);
    std::uniform_int_distribution amountDist(10, 100);
    std::uniform_int_distribution actionDist(1, 3);


    Logger &logger = Logger::getInstance(); // Accessing the "Logger" instance

    // random transactions
    for (int i = 0; i < iterations; i++)
    {
        const int accountNumber = accountDist(gen);
        const int amount  = amountDist(gen);
        const int action  = actionDist(gen);

        bankAccount *account;

        {
            std::lock_guard<std::mutex> lock(mtx);
            account = bank.getAccount(accountNumber);
        }

        time_t timestamp = std::time(nullptr); // Generate timestamp 

        {
            std::lock_guard<std::mutex> lock(printMtx);
            switch (action)
            {
            case 1:
                
                std::cout << "Customer" << clientid << " Account " << accountNumber
                            << " Deposit: " << amount << std::endl;
                try {
                    account->deposit(amount);

                    logger.logInfo(account->getId(), timestamp, account->getBalance(), amount); // Log for depositing

                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 2:
                std::cout << "Customer" << clientid << " Account " << accountNumber
                            << " Withdraw: " << amount << std::endl;
                try {
                    account->withdraw(amount);

                    logger.logInfo(account->getId(), timestamp, account->getBalance(), -amount); // Log for withdrawing

                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 3:
                std::cout << "Customer" << clientid << " Account " << accountNumber
                            << " Balance: " << account->getBalance() << std::endl;
                break;
            }
        }
        std::uniform_int_distribution waitTime(100, 3000);
        std::this_thread::sleep_for(std::chrono::milliseconds(waitTime(gen)));
    }
}

int main()
{
    Bank bank;

    // Create 5 accounts
    for (int i = 1000; i < 1005; ++i)
    {
        bank.addAccount(i, new bankAccount(1000, i));
    }

    std::vector<std::thread> threads;
    threads.reserve(10);
    for (int i = 0; i < 10; ++i)
    {
        // Create 10 clients and make 5 transactions each
        threads.emplace_back(client, std::ref(bank), i + 1, 5);
    }

    for (auto& t : threads)
    {
        t.join();
    }

    Logger &logger = Logger::getInstance();

    logger.logResults(bank.getAccounts());

    return 0;
}