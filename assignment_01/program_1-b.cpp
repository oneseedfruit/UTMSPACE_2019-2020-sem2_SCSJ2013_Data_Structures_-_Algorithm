// Universiti Teknologi Malaysia
// Semester 2 2019/2020
// ----------------------------------------------------------------------------
// SCSJ2013 Data Structures & Algorithms
// Assignment 1
// Lecturer: Madam Nor Bahiah Binti Ahmad
// ----------------------------------------------------------------------------
// Completed in a group of 2 by:
//
// Charlene Ng Andrew SX180355CSJS04
// Randy Tan Shaoxian SX180357CSJS04
// ----------------------------------------------------------------------------
// Files should be in a set, consisting of: 
//
// i) a_uml_class_diagram.png (answer for question a.)
// ii) program_1-b.cpp (this source file)
// iii) customer (input data to Program 1-B)
// ----------------------------------------------------------------------------
// Our answer for question a. is in the accompanying file named "a_uml_class_diagram.png"
// This source file contains our answers to questions b. to g.
// This source file can be compiled with a C++98 compiler (no need for C++11)
// ----------------------------------------------------------------------------
// Thank you Madam for this fun assignment! We had a great time doing it! :D

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

const int NUMBER_OF_CUSTOMERS = 20;

class Customer
{
private:
    std::string name; // customer name
    std::string status; // customer status: member or nonmember
    double parkingCharged; // amount charged for parking
    int parkHour; // total hours taken for parking

public:
    static std::ifstream infile; // (MODIFIED for b.) File to read values from, remember which file is being read

    std::string getName() const // (MODIFIED) Added const to promise to not change member values
        {
            return name;
        }

    int getHour() const // (MODIFIED) Added const to promise to not change member values
        {
            return parkHour;
        }

    std::string getStatus() const // (MODIFIED) Added const to promise to not change member values
        {
            return status;
        }

    double getCharged() const // (MODIFIED) Added const to promise to not change member values
        {
            return parkingCharged;
        }

    void readValue(std::string filename = "customer"); // (MODIFIED for b.) Default file name in parameter to read from
    void calcParkingCharges();
};

std::ifstream Customer::infile; // (MODIFIED for b.) Define static member outside class definition

// ========================================
// b.
// ========================================
void Customer::readValue(std::string filename) // (MODIFIED) readValue() takes in a string as file name
{
    if (!infile.is_open()) // Check if file is already opened
    {
        infile.open(filename.c_str(), std::ios::in); // Open file if not already opened

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
        infile.ignore(); // Workaround to fix problem caused by mixing >> and getline()
        std::getline(infile, status);

        std::string separator;
        std::getline(infile, separator);
    }

    // Don't need to call infile.close() explicitly in C++ as RAII lets the destructor do it implicitly
    // This is unlike C where a file has to be closed explicitly
}

// ========================================
// c.
// ========================================
void Customer::calcParkingCharges()
{
    if (status == "member")
    {
        // (DISCREPANCY IN QUESTION c.) Allow a ceiling of RM50 for members too?
        parkingCharged = parkHour > 2 ? parkHour >= 20 ? 50 : parkHour - 2 : 0;
    }
    else
    {
        parkingCharged = parkHour >= 20 ? 50 : 1.5 * parkHour;
    }
}

// ========================================
// d.
// ========================================
void displayInfoOfOneCustomer(const Customer &cust) // Function to display info about one customer
{
    std::cout << "Welcome " << cust.getName() << ", You are ";
    std::cout << (cust.getStatus() == "member"
                  ? "a member\nYou will get free parking for the first "
                  "two hours,\n"
                  : "not a member\nYou will be charged RM 50.00 for "
                  "parking more than 20 hours\n");
    std::cout << "Your Parking duration: " << cust.getHour() << " hours\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your Parking Payment: Rm " << cust.getCharged() << "\n\n";
}

// Function to display info about all customers in the array
void displayInfo(const Customer cust[], int count = NUMBER_OF_CUSTOMERS) // (MODIFIED) Added const to avoid modification to cust[], added count to specify array size
{
    for (int i = 0; i < count; ++i)
    {
        displayInfoOfOneCustomer(cust[i]);
    }
}

// ========================================
// e.
// ========================================
void swap(Customer &cust1, Customer &cust2) // Swap function for reuse across sorting functions
{
    Customer temp = cust1;
    cust1 = cust2;
    cust2 = temp;
}

void sortByParkingHours(Customer cust[], int count = NUMBER_OF_CUSTOMERS) // Improved bubble sort, compare integers
{
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

void sortByName(Customer cust[], int count = NUMBER_OF_CUSTOMERS) // Selection sort, compare strings instead
{
    for (int i = count - 1; i >= 1; --i)
    {
        int largestIndex = 0;

        for (int j = 1; j <= i; ++j)
        {
            if (cust[j].getName() > cust[largestIndex].getName())
            {
                largestIndex = j;
            }

            if (largestIndex != i)
            {
                swap(cust[largestIndex], cust[i]);
            }
        }
    }
}

// ========================================
// f.
// ========================================
// For duplicating the array to be sorted before searching, so that the original array stays unmodified (in case if it wasn't already sorted)
void copyArrayOfCustomers(const Customer custFrom[], Customer custTo[], int count = NUMBER_OF_CUSTOMERS)
{
    for (int i = 0; i < count; ++i)
    {
        custTo[i] = custFrom[i];
    }
}

// Sequential search, compare integers
int searchIndexByParkingHours(const Customer cust[], int hours, Customer out[], int count = NUMBER_OF_CUSTOMERS)
{
    // Duplicate the array to be sorted before searching, so that the original array stays unmodified (if it wasn't already sorted before)
    Customer temp[count];
    copyArrayOfCustomers(cust, temp);
    sortByParkingHours(temp, count);

    int searchIndex = -1;

    for (int i = 0; i < count; ++i)
    {
        if (hours < temp[i].getHour())
        {
            break;
        }
        else if (hours == temp[i].getHour())
        {
            searchIndex = i;
            break;
        }
    }

    // Copy duplicated array to output array so the result can be queried from outside the function 
    // without affecting the original array (if it wasn't already sorted before)
    copyArrayOfCustomers(temp, out);

    return searchIndex;
}

// Binary search, compare strings
int searchIndexByName(const Customer cust[], const std::string &name, Customer out[], int count = NUMBER_OF_CUSTOMERS)
{
    // Duplicate the array to be sorted before searching, so that the original array stays unmodified (if it wasn't already sorted before)
    Customer temp[count];
    copyArrayOfCustomers(cust, temp);
    sortByName(temp, count);

    int first = 0;
    int last = count - 1;
    int middle;
    int pos = -1;

    bool isFound = false;

    while(!isFound && first <= last)
    {
        middle = (first + last) / 2;

        if (temp[middle].getName() == name)
        {
            isFound = true;
            pos = middle;
        }
        else if (temp[middle].getName() > name)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }

    // Copy duplicated array to output array so the result can be queried from outside the function
    // without affecting the original array (if it wasn't already sorted before)
    copyArrayOfCustomers(temp, out);

    return pos;
}

// Overloaded displaySearchResult() to show result from searchIndexByParkingHours()
void displaySearchResult(int hours, const Customer cust[], int count = NUMBER_OF_CUSTOMERS)
{
    Customer sortedCust[count];
    int searchIndex = searchIndexByParkingHours(cust, hours, sortedCust, count);

    if (searchIndex > -1) // Only display result if exact match is found
    {
        Customer result = sortedCust[searchIndex];

        std::cout << "\nSearch result(s):\n\n";
        std::cout << "=====================================================\n";

        for (int i = 0, j = 0; i < count; ++i)
        {
            if (cust[i].getHour() == result.getHour())
            {
                std::cout << "Result #" << ++j << ":\n";
                std::cout << "----------\n";
                displayInfoOfOneCustomer(cust[i]);
            }
        }

        std::cout << "=====================================================\n\n";
    }
    else
    {
        std::cout << "\nNo customer in the list has parked for " << hours << " hours!\n\n";
    }
}

// Overloaded displaySearchResult() to show result from searchIndexName()
void displaySearchResult(std::string name, const Customer cust[], int count = NUMBER_OF_CUSTOMERS)
{
    Customer sortedCust[count];
    int searchIndex = searchIndexByName(cust, name, sortedCust, count);

    if (searchIndex > -1) // Only display result if exact match is found
    {
        Customer result = sortedCust[searchIndex];

        std::cout << "\nSearch result:\n\n";
        std::cout << "=====================================================\n";
        displayInfoOfOneCustomer(result);
        std::cout << "=====================================================\n\n";
    }
    else
    {
        std::cout << "\nNo customer in the list is named exactly \"" << name << "\"!\n\n";
    }
}

int main() // (MODIFIED) Changed to return int to follow C++ convention
{
    Customer cust[NUMBER_OF_CUSTOMERS]; // (MODIFIED) Changed 20 to a constant NUMBER_OF_CUSTOMERS

    for (int i = 0; i < NUMBER_OF_CUSTOMERS; ++i) // (MODIFIED) Changed 20 to a constant NUMBER_OF_CUSTOMERS
    {
        cust[i].readValue();
        cust[i].calcParkingCharges();
    }

    // ========================================
    // g. Code for a simple menu
    // ========================================
    int option = 0;
    int optionSort = 0;
    int optionSearch = 0;

    while (option != 4)
    {
        std::cout << "Choose an option:\n";
        std::cout << "1. Sort\n";
        std::cout << "2. Search\n";
        std::cout << "3. Display\n";
        std::cout << "4. Exit\n";

        std::cin >> option;
        std::cout << "\n";

        switch (option)
        {
            case 1:                
                while (optionSort != 3)
                {
                    std::cout << "=> 1. Sort by parking hours (ascending)\n";
                    std::cout << "=> 2. Sort by customer names (ascending)\n";
                    std::cout << "=> 3. Back\n";

                    std::cin >> optionSort;

                    switch (optionSort)
                    {
                        case 1:
                            sortByParkingHours(cust);
                            std::cout << "==> Sorted successfully by parking hours (ascending)!\n";
                            break;

                        case 2:
                            sortByName(cust);
                            std::cout << "==> Sorted successfully by customer names (ascending)!\n";
                            break;
                    }

                    std::cout << "\n";
                }

                optionSort = 0;

                break;
            
            case 2:
                while (optionSearch != 3)
                {
                    std::cout << "=> 1. Search by parking hours\n";
                    std::cout << "=> 2. Search by customer names (exact match, case-sensitive)\n";
                    std::cout << "=> 3. Back\n";

                    std::cin >> optionSearch;

                    switch (optionSearch)
                    {
                        case 1:
                            int hours;
                            std::cout << "==> Search by parking hours: ";
                            std::cin >> hours;
                            displaySearchResult(hours, cust);
                            break;
                        
                        case 2:
                            std::string name;
                            std::cout << "==> Search by name: ";
                            std::cin.ignore();
                            std::getline(std::cin, name);
                            displaySearchResult(name, cust);
                            break;
                    }

                    std::cout << "\n";
                }

                optionSearch = 0;

                break;
            
            case 3:
                std::cout << "=> Displaying all customers:\n\n";
                std::cout << "=====================================================\n";
                
                displayInfo(cust);

                std::cout << "=====================================================\n\n";

                break;

            case 4:
                std::cout << "Program exited successfully!\n";
                break;
        }
    }

    return 0; // (MODIFIED) Changed to return 0 to follow C++ convention
}
