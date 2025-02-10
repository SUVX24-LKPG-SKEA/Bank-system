#include "Logger.hpp"
#include <iostream>

Logger::Logger()
= default;

/**
 * @brief Prints a new entry to the transaction log
 * 
 * @param accountId The account number
 * @param timestamp Timestamp when the transaction was performed
 * @param accountBalance The balance of the account.
 * @param difference The transaction size, negative numbers indicates withdrawals.
 */
void Logger::logInfo(const int accountId, const time_t timestamp, const double accountBalance, const double difference)
{
    if (std::ofstream file("transaction_log.txt", std::ios::app); file.is_open())
    {
        file << "Account Number: " << accountId << "\nTime: " << timestamp << "\nTransaction: " << difference << "\n" <<
            "Account balance: " << accountBalance << "\n" << std::endl;
        file.close();
    }
}

/**
 * @brief Prints final results to console.
 * 
 * @param accounts A map to all accounts to be printed.
 */
void Logger::logResults(const std::map<int, BankAccount*>& accounts)
{
    std::cout << "\n--- Transaction report ---\n";
    for (auto [key, value] : accounts)
    {
        std::cout << "\nAccount " << key <<
            "\n\tBalance: " << value->getBalance() <<
            "\n\tWithdraws: " << value->getWithdraws() <<
            "\n\tDeposits: " << value->getDeposits() << std::endl;
    }
}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}
