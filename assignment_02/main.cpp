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
// i) linkedList.cpp___ (given linked list program, renamed to cpp___ to avoid it
//                       from being targeted for compilation because we used the 
//                       "*" wildcard in our compilation command)
//
// our modified program (all the following files constitute one program):
//
// ii) Node.hpp
// iii) List.hpp
// iv) List.cpp
// v) StudentInfo.hpp
// vi) main.cpp
// ----------------------------------------------------------------------------
// The source files can be compiled with a C++98 compiler (no need for C++11).
// Files ii, iii, iv, v, and vi should be compiled together.
// 
// Compiled using g++ in Manjaro Linux using the following command:
//
// g++ --std=c++98 *.cpp -o linkedList
//
// to output the executable file "linkedList"
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

    aList.DeleteNode("SX180357CSJS04");

    aList.DisplayList();

    return 0;
}
