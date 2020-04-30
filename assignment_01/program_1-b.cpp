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

// (FOR QUESTION e.)Function prototype to sort customer array by parking hours, so can be called in displayInfo()
void sortByParkingHours(Customer[], int count = 20);

// d.
void displayInfo(Customer cust[], int count = 20)
{
    sortByParkingHours(cust, count); // (FOR QUESTION e.)

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

// e.
void swap(Customer &cust1, Customer &cust2) // Swap function
{
    Customer temp = cust1;
    cust1 = cust2;
    cust2 = temp;
}

void sortByParkingHours(Customer cust[], int count) // Improved bubble sort
{
    int temp;
    bool isSorted = false;

    for (int i = 1; i < count && !isSorted; ++i)
    {
        isSorted = true;

        for (int j = 0; j < count - i; ++j)
        {
            if (cust[j].getHour() > cust[j + 1].getHour())
            {
                swap(cust[j], cust[j + 1]);
                isSorted = false;
            }
        }
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
