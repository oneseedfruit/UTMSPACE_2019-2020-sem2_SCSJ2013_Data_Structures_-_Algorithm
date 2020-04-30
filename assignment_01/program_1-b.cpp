#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class Customer
{
private:
    std::string name; // customer name
    std::string status; // customer status: member or nonmember
    double parkingCharged; // amount charged for parking
    int parkHour; // total hours taken for parking

public:
    static std::ifstream infile; // (MODIFIED for b.) File to read values from

    std::string getName()
        {
            return name;
        }

    int getHour()
        {
            return parkHour;
        }

    std::string getStatus()
        {
            return status;
        }

    double getCharged()
        {
            return parkingCharged;
        }

    void readValue(std::string filename = "customer"); // (MODIFIED for b.) Default file name in parameter
    void calcParkingCharges();
};

std::ifstream Customer::infile; // (MODIFIED for b.) Define static member outside class definition

// b.
void Customer::readValue(std::string filename) // (MODIFIED) readValue() takes in a string as file name
{
    if (!infile.is_open()) // Check if file is already opened
    {
        infile.open(filename.c_str(), std::ios::in);

        if (!infile) // Check if file is opened successfully
        {
            std::cout << "Error! File \"" << filename << "\" could not be opened.\n";
            return;
        }
    }

    if (!infile.eof()) // If it is not end of file
    {
        std::getline(infile, name);
        infile >> parkHour;
        infile.ignore();
        std::getline(infile, status);

        std::string separator;
        std::getline(infile, separator);
    }

    // Don't need to call infile.close() explicitly in C++ as RAII lets the destructor do it implicitly
    // This is unlike C where a file has to be closed explicitly
}

// c.
void Customer::calcParkingCharges()
{
    if (status == "member")
    {
        // (DISCREPANCY IN QUESTION c.) Allow a ceiling of RM50 for members too
        parkingCharged = parkHour > 2 ? parkHour >= 20 ? 50 : parkHour - 2 : 0;
    }
    else
    {
        parkingCharged = parkHour >= 20 ? 50 : 1.5 * parkHour;
    }
}

// d.
void displayInfo(Customer cust[], int count = 20)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << "Welcome " << cust[i].getName() << ", You are ";
        std::cout << (cust[i].getStatus() == "member"
                      ? "a member\nYou will get free parking for the first "
                      "two hours,\n"
                      : "not a member\nYou will be charged RM 50.00 for "
                      "parking more than 20 hours\n");
        std::cout << "Your Parking duration: " << cust[i].getHour()
                  << " hours\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Your Parking Payment: Rm " << cust[i].getCharged()
                  << "\n";
        std::cout << "\n";
    }
}

int main()
{
    Customer cust[20];

    for (int i = 0; i < 20; ++i)
    {
        cust[i].readValue();
        cust[i].calcParkingCharges();
    }

    displayInfo(cust);

    return 0;
}
