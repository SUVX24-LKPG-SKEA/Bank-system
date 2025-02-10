#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <map>
#include "BankAccount.h"

/**
 * @brief Singleton to handle logging
 */
class Logger {
private:
    std::mutex mtx;
    std::condition_variable cv;
    Logger();
public:
    static void logInfo(int accountId, time_t timestamp, double accountBalance, double difference);
    static void logResults(const std::map<int, BankAccount*>& accounts);
    static Logger &getInstance();
};

#endif