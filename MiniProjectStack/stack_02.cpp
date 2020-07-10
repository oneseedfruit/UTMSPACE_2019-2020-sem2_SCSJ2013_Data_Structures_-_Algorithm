// stack_02.cpp
          
#include <iostream>
// #include <conio.h> // commented out because doesn't exist on Linux systems, non-standard, cannot compile with this on Linux
//
// We (Randy & Charlene) only have Manjaro Linux, we don't use Microsoft Windows.
//
// ----------------------------------------------------------------------------
// Completed in a group of 2 by:
//
// Charlene Ng Andrew SX180355CSJS04
// Randy Tan Shaoxian SX180357CSJS04
//
// ----------------------------------------------------------------------------
//

using namespace std;

#define MAXSTACK 10
class Stack
{    private:
        int top;
        char data[MAXSTACK];              
     public:
        Stack(){   top = -1;  }
        bool isFull();
        bool isEmpty();        
        void push(char);   
        void printLIFO();  
        void printFIFO();
};

bool Stack::isFull()
{    return (top == (MAXSTACK - 1));    }

bool Stack::isEmpty()
{    return (top == (-1));    }

void Stack::push(char item)
{   if (!isFull())
    {   top++;
        data[top] = item; 
        cout << "Push operation success! item: "<<item<< endl;
    }     
    else
    {  cout << "Push operation fail-stack is full!"<< endl; }
}
// Task 2-b for stack 
void Stack::printFIFO()
{
   // Task 2-b,write code to print item in stack 
   //using FIFO concept
   cout << "FIFO printing" << endl;

   for (int i = 0; i <= top; ++i)
   {
       cout << data[i];
   }
}
// Task 2-a for stack 
void Stack::printLIFO()
{   // Task 2-a, write code to print item in stack 
    // using LIFO concept

    cout << "LIFO printing" << endl;
    
    for (int i = top; i > -1; --i)
    {
        cout << data[i];
    }
}

int main()
{   Stack stack;      
    stack.push('a');
    stack.push('b');
    stack.push('c'); 
    cout << endl;
    stack.printFIFO();
    cout << endl;
    cout << endl; 
    stack.printLIFO(); 

    // getche(); // commented out because doesn't exist on Linux systems, non-standard, cannot compile with this on Linux
    return 0;
}

