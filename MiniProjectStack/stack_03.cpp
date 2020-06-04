// stack_03.cpp         
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
{   private:
        int top;
        char data[MAXSTACK];              
    public:
        Stack() {  top = -1; }
        bool isFull();
        bool isEmpty();        
        void push(char);    
        void pop();        
        void emptyStack();               
};

bool Stack::isFull()
{    return (top == (MAXSTACK - 1));   }

bool Stack::isEmpty()
{    return (top == (-1));    }

void Stack::push(char item)
{   if (!isFull())
    {   top++;
        data[top] = item; 
        cout << "Push operation success! item:"<<item<< endl;
    }     
    else
    {   cout << "Push operation fail-stack is full!" << endl;}
}

void Stack::pop()
{   if (!isEmpty())     
    {   char item = data[top];
        top--;
        cout << item ;                          
    }                   
}

// Task 3 for stack 
void Stack::emptyStack()
{       // Task 3, write code for emptyStack() 
    for (int i = top; i > -1; --i)
    {
        pop();
        if (isEmpty())
        {
            cout << endl << "Stack is empty";
        }
    }
}

int main()
{                
    Stack stack;    
        
    stack.push('d');
    stack.push('e');
    stack.push('s');
    stack.push('s');
    stack.push('e');
    stack.push('r');
    stack.push('t');
    stack.push('s');
    cout << endl;
    cout << "Empty the content of the stack with the following order : \n" ;
    stack.emptyStack();
    cout << endl; 
    
    // getche();  // commented out because doesn't exist on Linux systems, non-standard, cannot compile with this on Linux
    return 0;
}

