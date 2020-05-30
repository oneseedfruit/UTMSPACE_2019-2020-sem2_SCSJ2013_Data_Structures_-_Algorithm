// Universiti Teknologi Malaysia
// Semester 2 2019/2020
//
// ----------------------------------------------------------------------------
// SCSJ2013 Data Structures & Algorithms
// Assignment 2
// Lecturer: Madam Nor Bahiah Binti Ahmad
//
// ----------------------------------------------------------------------------
//  Provied task:
//
// "Assignment 2 -
//
//  Change the given linked list program that able to store student information, 
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
//
// ----------------------------------------------------------------------------
// Our submitted files should be in a set, consisting of: 
//
//      1. linkedList.cpp___ (given linked list program, renamed to cpp___ to 
//                            avoid it from being targeted for compilation 
//                            because we used the "*" wildcard in our 
//                            compilation command)
//
// and our modified program (all the following files constitute one program):
//
//      2. Node.hpp
//      3. Node.cpp
//      4. List.hpp
//      5. List.cpp
//      6. StudentInfo.hpp
//      7. main.cpp
// 
// In addition to that, there is also a sample input file:
//
//      8. studentdata (text file containing a list of student information)
// 
// and a recorded video of the program execution:
//
//      9. programoutputvideo.mp4
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
//      7. Removed unused header (conio.h), this header is not part of any
//         standard library, it is mostly only used by MS-DOS compilers to 
//         provide console input/output, so it it also not available on Linux. 
//         It is also a C header which is not meant to be used in a C++ program.
//         (To keep a window open, instead of using a non-standard library, 
//          prompt for input from stdin,
//          e.g. use std::cin.get() from the iostream header.)
//      8. Fixed memory leak by deleting all dynamic allocations in the heap
//         the allocations are not used anymore.
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
// to output the executable file "linkedList". The "--std=c++98" option is used
// because the latest g++ installed in our systems default to c++11.
//
// On Windows, if using Dev-C++, just create a new project, then add all the 
// files to the same project and compile then run.
//
// ----------------------------------------------------------------------------
// Thank you Madam for this fun assignment! We had a great time doing it! :D
// It is even more interesting than the previous assignment!
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Node.hpp"
#include "List.hpp"

void ShowMenuOptions(bool verbose = false);
void ShowCommandLineHelp(char *binname, bool verbose = false);

int main(int argc, char **argv)
{
    bool verbose = false;
    std::string filename = "studentdata";
    
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {   
            if (argv[i][1] == '-')
            {
                std::string argvi(argv[i]);

                if (argvi.compare("--verbose") == 0)
                {
                    verbose = true;
                }
                else if (argvi.compare("--file") == 0)
                {
                    filename = argv[i + 1];
                }
                else if (argvi.compare("--help") == 0)
                {
                    ShowCommandLineHelp(argv[0], verbose);
                    return 0;
                }
                else
                {
                    std::cout << "Invalid argument(s) provided!\n\n";
                    ShowCommandLineHelp(argv[0], verbose);
                    return 0;
                }
            }
            else
            {
                switch (argv[i][1])
                {
                    case 'V':
                    case 'v':
                        verbose = true;
                        break;

                    case 'F':
                    case 'f':
                        filename = argv[i + 1];
                        break;

                    case 'H':
                    case 'h':
                        ShowCommandLineHelp(argv[0], verbose);
                        return 0;
                        break;

                    default:
                        std::cout << "Invalid argument(s) provided!\n\n";
                        ShowCommandLineHelp(argv[0], verbose);
                        return 0;
                }
            }
        }
    }

    List aList;

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
    std::string inputString, inputString2, inputString3;
    float inputFloat = -1;
    List bList;
    char inputChar = ' ';
    int findFlag = 0;

    ShowMenuOptions(verbose);

    while (option != 0)
    {
        std::cout << "\nYour option (9 to show menu options): ";
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
                        ++findFlag;
                    }                    
                }

                if (findFlag == 0)
                {
                    std::cout << "\nStudent information not found!\n";
                }

                bList.ClearListAndFreeMemory(verbose);

                option = -1;
                findIndex = -1;
                inputFloat = -1;
                findFlag = 0;
                break;

            case 4:
                if (verbose)
                {
                    std::cout << "\n\t>>> Operation [INSERT] new student information:\n";
                }

                inputString = "";
                inputString2 = "";
                inputString3 = "";                

                std::cout << "\n---------------------------------------------\n";

                while (inputString.empty() || inputString.length() < 3 ||
                            inputString.find('0') != std::string::npos ||
                            inputString.find('1') != std::string::npos ||
                            inputString.find('2') != std::string::npos ||
                            inputString.find('3') != std::string::npos ||
                            inputString.find('4') != std::string::npos ||
                            inputString.find('5') != std::string::npos ||
                            inputString.find('6') != std::string::npos ||
                            inputString.find('7') != std::string::npos ||
                            inputString.find('8') != std::string::npos ||
                            inputString.find('9') != std::string::npos)
                {
                    std::cout << "| Student name: ";
                    std::getline(std::cin, inputString);
                }
                
                while (inputString2.empty() || inputString2.length() < 10 ||
                        aList.FindNextNodeWith(inputString2, verbose) >= 0)
                {
                    std::cout << "| Matric number: ";
                    std::getline(std::cin, inputString2);
                }

                while (inputString3.empty() || inputString3.length() < 4)
                {
                    std::cout << "| Program: ";
                    std::getline(std::cin, inputString3);       
                }

                while (inputFloat < 0 || inputFloat > 4)
                {
                    std::cout << "| CGPA: ";
                    std::cin >> inputFloat;
                    std::cin.ignore();
                }

                std::cout << "\n---------------------------------------------\n";

                aList.InsertNode(inputString, inputString2, inputString3, inputFloat, verbose);

                option = -1;                
                inputFloat = -1;                
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

void ShowCommandLineHelp (char *binname, bool verbose)
{
    std::cout << "Usage: " << binname << " [OPTION]... [FILE]...\n";
    std::cout << "Linked List demo program written for an assignment in a UTMSPACE class,\n";
    std::cout << "SCSJ2013 Data Structures & Algorithm, during the 2nd semester of the \n";
    std::cout << "2019/2020 session.\n\n";
    
    std::cout << "  -H, -h, --help                    show this help output\n";
    std::cout << "  -V, -v, --verbose                 verbose mode\n";
    std::cout << "  -F, -f, --file [/path/to/file]    specify an input file\n\n";
}