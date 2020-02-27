#include <string>

enum class AccountType { savings, current };

class Account
{
private:
    std::string accountName;
    std::string accountNumber;
    int accountType;
    float accountBalance;

public:
    Account(std::string accName = "Unnamed",
            std::string accNumber = "-1",
            int accType = -1,
            float accBalance = -INTMAX_MAX);

    std::string getAccountNumber() const;
    float getBalance() const;
    void withdraw(float);
    void deposit(float);
    void transfer(float, Account &);
    void printDetail() const;
};
