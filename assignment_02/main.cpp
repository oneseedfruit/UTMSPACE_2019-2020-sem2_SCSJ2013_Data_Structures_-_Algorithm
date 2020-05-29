// Universiti Teknologi Malaysia
// Semester 2 2019/2020
// ----------------------------------------------------------------------------
// SCSJ2013 Data Structures & Algorithms
// Assignment 2
// Lecturer: Madam Nor Bahiah Binti Ahmad
// ----------------------------------------------------------------------------
//
// "Change the given linked list program that able to store student information, 
//  such as the student name, matric number, program and cgpa.  Create menu to 
//  provide choices for the user to insert, delete, display and search from the 
//  list.  You can also sort the list based on any criteria. 
//
//  The work can be done with 2 members per group."
//
// ----------------------------------------------------------------------------
// Completed in a group of 2 by:
//
// Charlene Ng Andrew SX180355CSJS04
// Randy Tan Shaoxian SX180357CSJS04

// ----------------------------------------------------------------------------
// Files should be in a set, consisting of: 
//
//      1. linkedList.cpp___ (given linked list program, renamed to cpp___ to 
//                            avoid it from being targeted for compilation 
//                            because we used the "*" wildcard in our 
//                            compilation command)
//
// our modified program (all the following files constitute one program):
//
//      2. Node.hpp
//      3. Node.cpp
//      4. List.hpp
//      5. List.cpp
//      6. StudentInfo.hpp
//      7. main.cpp
//      8. studentdata (text file containing a list of student information)
//
// Our modifications include but not limited to:
//
//      1. Split the code into multiple files for easier management and
//         readability.
//      2. Changed the "currIndex" variable to be zero-based. We are prefer
//         to start the count from 0, so all "currIndex" start from 0.
//      3. Refactored code for better readability.
//      4. Reused the find node functions in the delete function.
//      5. Added some functions for reuse, convenience, and to decrease errors.
//      6. Added const keyword to functions not meant to modify data members.
//
// ----------------------------------------------------------------------------
// The source files can be compiled with a C++98 compiler (no need for C++11).
// Files 2, 3, 4, 5, 6, and 7 should be compiled together as one program.
// 
// Compiled using g++ in Manjaro Linux by running the following command in the
// directory where the files are placed:
//
//              g++ --std=c++98 *.cpp -o linkedList
//
// to output the executable file "linkedList"
//
// ----------------------------------------------------------------------------
// Thank you Madam for this fun assignment! We had a great time doing it! :D

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Node.hpp"
#include "List.hpp"

void ShowMenuOptions(bool verbose = false);

int main(void)
{
    bool verbose = false;

    List aList;
    std::string filename = "studentdata";

    std::ifstream infile(filename.c_str(), infile.in);

    std::string name, matric, program;
    float cgpa;

    if (infile.is_open()) // Check if file is already opened
    {
        while (!infile.eof()) // If it is not end of file
        {
            std::getline(infile, name);
            if (name.empty()) break;

            std::getline(infile, matric);
            std::getline(infile, program);
            infile >> cgpa;
            infile.ignore(); // Workaround to fix problem caused by mixing >> and getline()
                        
            std::string separator;
            std::getline(infile, separator);            

            aList.InsertNode(name, matric, program, cgpa);
        }
    }
    
    infile.close();

    int option = -1;
    int findIndex = -1;
    std::string inputString;
    float inputFloat = -1;
    List bList;
    char inputChar = ' ';

    ShowMenuOptions(verbose);

    while (option != 0)
    {
        std::cout << "\nYour option: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option)
        {
            case 1:
                aList.DisplayList(verbose);
                option = -1;
                break;

            case 2:
                std::cout << "Enter a matric number to find student information: ";
                std::getline(std::cin, inputString);
                findIndex = aList.FindNextNodeWith(inputString, verbose);
                if (findIndex >= 0)
                {
                    aList.GetNextNodeFromIndex(findIndex)->DisplayNode(verbose);
                }
                else
                {
                    std::cout << "\nStudent information not found!\n";
                }
                option = -1;
                findIndex = -1;
                inputFloat = -1;
                break;

            case 3:
                std::cout << "Enter a CGPA to find student information: ";
                std::cin >> inputFloat;
                std::cin.ignore();
                
                for (int i = 0; i < aList.Count(); ++i)
                {
                    bList.InsertNode(aList.GetNextNodeFromIndex(i), verbose);                    
                }

                for (int i = 0; i < bList.Count(); ++i)
                {
                    findIndex = bList.FindNextNodeWith(inputFloat, verbose);
                    if (findIndex >= 0)
                    {
                        bList.GetNextNodeFromIndex(findIndex)->DisplayNode(verbose);
                        bList.DeleteNextNodeWith(bList.GetNextNodeFromIndex(findIndex)->data.matric, verbose);
                    }
                }

                bList.ClearListAndFreeMemory(verbose);;

                option = -1;
                findIndex = -1;
                inputFloat = -1;
                break;

            case 4:
                break;

            case 5:
                std::cout << "Enter a matric number to delete student information: ";
                std::getline(std::cin, inputString);

                findIndex = aList.FindNextNodeWith(inputString, verbose);
                if (findIndex >= 0)
                {
                    aList.GetNextNodeFromIndex(findIndex)->DisplayNode(verbose);
                    std::cout << "\n";

                    while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n')
                    {
                        std::cout << "Are you sure? Y/N: ";
                        std::cin >> inputChar;
                        std::cin.ignore();
                    }
                    
                    switch (inputChar)
                    {
                        case 'Y':
                        case 'y':
                            aList.DeleteNextNodeWith(inputString, verbose);
                            std::cout << "\nStudent information deleted successfully!\n";
                            break;
                        
                        case 'N':
                        case 'n':
                            std::cout << "\nStudent information not deleted.\n";
                            break;
                    }
                }
                else 
                {
                    std::cout << "\nStudent information not found! ";
                    std::cout << "Nothing was deleted.\n";
                }

                option = -1;
                findIndex = -1;
                inputFloat = -1;
                inputChar = ' ';
                break;

            case 9:
                ShowMenuOptions(verbose);
                break;
        }
    }

    std::ofstream outfile(filename.c_str(), outfile.out | outfile.trunc);

    for (int i = 0; i < aList.Count(); ++i)
    {
        if (outfile.is_open())
        {        
            Node *n = aList.GetNextNodeFromIndex(i);
            outfile << n->data.name << "\n";
            outfile << n->data.matric << "\n";
            outfile << n->data.program << "\n";
            outfile << std::setprecision(2) << std::fixed;
            outfile << n->data.cgpa << "\n";
            outfile << "\n";
        }
    }

    outfile.close();

    aList.ClearListAndFreeMemory(verbose);

    return 0;
}

void ShowMenuOptions(bool verbose)
{
    if (verbose)
    {
        std::cout << "\n\t>>> Operation [SHOW MENU OPTIONS]:\n";
    }
    std::cout << "\nChoose an option (type a number):\n";
    std::cout << "1: Show all student information.\n";
    std::cout << "2: Find student information by matric number.\n";
    std::cout << "3: Find all student information by CGPA.\n";
    std::cout << "4: Add new student information.\n";
    std::cout << "5: Delete student information.\n";
    std::cout << "9: Show menu options.\n";
    std::cout << "0 or any character: Exit\n";
}