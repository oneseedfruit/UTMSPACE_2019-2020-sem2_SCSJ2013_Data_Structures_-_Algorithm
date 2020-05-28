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
#include "Node.hpp"
#include "List.hpp"
using std::cout;

int main(void)
{
    List aList;

    aList.InsertNode("Randy Tan Shaoxian", "SX180357CSJS04", "SCSJ", 3.89);
    aList.InsertNode("Charlene Ng Andrew", "SX180355CSJS04", "SCSJ", 4.0);
    aList.InsertNode("Brachydios", "SX200357BLAS04", "SCSJ", 3.98);
    aList.InsertNode("Deviljho", "SX200355VORA04", "SCSJ", 4.0);

    aList.DisplayList();

    // aList.DeleteNextNodeWith("SX180357CSJS04");
    // aList.DeleteNextNodeWith("SX180355CSJS04");
    // aList.DeleteNextNodeWith("SX200357BLAS04");
    aList.DeleteNextNodeWith("SX200355VORA04");

    aList.DisplayList();


    for (int i = 0; i < 5; ++i)
    {   
        if (aList.GetNextNodeFromIndex(i) != NULL)
            cout << "Node " << i << " is " << aList.GetNextNodeFromIndex(i)->data.matric << "\n";
    }

    cout << "\n";
    cout << "\"SX180357CSJS04\" found at " << aList.FindNextNodeWith("SX180357CSJS04") << "!\n";
    cout << "\"SX180355CSJS04\" found at " << aList.FindNextNodeWith("SX180355CSJS04") << "!\n";
    cout << "\"SX200357BLAS04\" found at " << aList.FindNextNodeWith("SX200357BLAS04") << "!\n";
    cout << "\"SX200355VORA04\" found at " << aList.FindNextNodeWith("SX200355VORA04") << "!\n";

    return 0;
}
