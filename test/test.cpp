#include <catch2/catch_test_macros.hpp>
#include "BankAccount.h"
#include "Bank.hpp" // Will be renamed

TEST_CASE("BankAccount class", "[bankaccount],[class]")
{
    BankAccount bankAccount(600, 1);

    REQUIRE_THROWS(bankAccount.withdraw(-1));
    REQUIRE_THROWS(bankAccount.deposit(-1));

    REQUIRE_THROWS(bankAccount.withdraw(-1500));
    REQUIRE_THROWS(bankAccount.deposit(-1500));

    REQUIRE_THROWS(bankAccount.withdraw(0));
    REQUIRE_THROWS(bankAccount.deposit(0));

    REQUIRE(bankAccount.getBalance() == 600);

    bankAccount.withdraw(300);
    REQUIRE(bankAccount.getBalance() == 300);

    bankAccount.deposit(150);
    REQUIRE(bankAccount.getBalance() == 450);

    REQUIRE_THROWS(bankAccount.withdraw(10000));
}

TEST_CASE("Bank class", "[bank],[class]")
{
    Bank bank;

    REQUIRE_NOTHROW(bank.addAccount(1, new BankAccount(50, 1000)));
    
    REQUIRE_NOTHROW(bank.getAccount(1));
    REQUIRE_THROWS(bank.getAccount(-1));
}