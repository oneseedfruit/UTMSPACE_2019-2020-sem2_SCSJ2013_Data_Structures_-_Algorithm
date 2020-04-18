#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdint>
#include "Account.hpp"

Account getAccountFromAccNumber(const std::string &, const Account[], int);
bool doesAccountExist(const std::string &, const Account[], int);

int main()
{
    Account acc1("Randy Tan Shaoxian",
                 "SX180357CSJS04",
                 (int) AccountType::savings,
                 50);
    Account acc2("Charlene Ng Andrew",
                 "SX180355CSJS04",
                 (int) AccountType::savings,
                 3000);

    const int ACCOUNT_COUNT = 10;
    Account accounts[ACCOUNT_COUNT];

    std::string infilename;
    std::cout << "Name of input file? (\"accounts.dat\" by default): ";
    std::getline(std::cin, infilename);

    infilename = infilename.empty() ? "accounts.dat" : infilename;

    std::ifstream in(infilename.c_str());

    if (in.is_open())
    {
        for (int i = 0; !in.eof(); ++i)
        {
            std::string accName;
            std::getline(in, accName);

            std::string accNumber;
            std::getline(in, accNumber);

            std::string temp;

            int accType;
            in >> accType;

            float accBalance;
            in >> accBalance;

            in.clear();
            in.ignore(INTMAX_MAX, '\n');
            std::getline(in, temp);

            accounts[i] = Account(accName, accNumber, accType, accBalance);
        }

        // for (int i = 0; i < ACCOUNT_COUNT; ++i)
        // {
        //     accounts[i].printDetail();
        // }
    }
    else
    {
        std::cerr << "File \"" << infilename << "\" does not exist!\n";
        return 0;
    }

    in.close();

    std::cout << "\n";

    std::string fromAccNumber, toAccNumber;
    std::cout << "Enter account number: ";
    std::getline(std::cin, fromAccNumber);
    std::cout << "Enter target account number: ";
    std::getline(std::cin, toAccNumber);

    if (doesAccountExist(fromAccNumber, accounts, ACCOUNT_COUNT) &&
        doesAccountExist(toAccNumber, accounts, ACCOUNT_COUNT))
    {
        float amount = 0;
        std::cout << "How much to transfer?: RM";
        std::cin >> amount;

        Account from = getAccountFromAccNumber(fromAccNumber, accounts, ACCOUNT_COUNT);
        Account to = getAccountFromAccNumber(toAccNumber, accounts, ACCOUNT_COUNT);

        from.transfer(amount, to);

        std::cout << "\nFrom: ";
        from.printDetail();
        std::cout << "To: ";
        to.printDetail();
    }
    else
    {
        std::cout << "Invalid account number entered!\n";
    }


    return 0;
}

Account getAccountFromAccNumber(const std::string &accNumber, const Account accounts[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        if (accounts[i].getAccountNumber() == accNumber)
        {
            return accounts[i];
        }
    }
    return Account();
}

bool doesAccountExist(const std::string &accNumber, const Account accounts[], int count)
{
    return getAccountFromAccNumber(accNumber, accounts, count).getAccountNumber() != "-1";
}
