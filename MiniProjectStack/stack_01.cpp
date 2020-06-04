// stack_01.cpp        
#include <iostream>
// #include <conio.h> // commented out because doesn't exist on Linux systems, non-standard, cannot compile with this on Linux
//
// We (Randy & Charlene) only have Manjaro Linux, we don't use Microsoft Windows.
//

using namespace std;

#define MAXSTACK 10
class Stack
{   private:
        int top;
        char data[MAXSTACK];              
    public:
        Stack();
        bool isFull();
        bool isEmpty();        
        void push(char);   
        char pop(); // return the popped item
}; // end Stack class declaration

Stack::Stack() {    top = -1;    }

bool Stack::isFull()
{    return (top == (MAXSTACK - 1));  }

bool Stack::isEmpty()
{    return (top == (-1));  }

void Stack::push(char item)
{   if (!isFull())
    {  top++;
       data[top] = item; 
       cout << "Push operation success!item: " << item << endl;
    }     
    else
    {  cout << "Push operation fail-stack is full! " << endl; }
}

// Task 1-a for stack 
char Stack::pop()
{   // Task 1-a write code to pop item 
    // and return the popped item
    if (isEmpty())
    {
        return '*';
    }
    else
    {
        int poppedIndex = top;
        top -= 1;
        return data[poppedIndex];
    }
}

// Task 1-b for stack
void printPop(char item)
{     // Task 1-b write code for printPop(char)
    if (item == '*')
    {
        cout << "Pop operation fail - stack is empty!" << endl;
    }
    else
    {
        cout << "Popped item: " << item << endl;
    }
    
}
int main()
{   Stack aStack;      
    aStack.push('a');
    aStack.push('b');
    aStack.push('c');   
    
    printPop(aStack.pop());
    printPop(aStack.pop());
    printPop(aStack.pop());
    printPop(aStack.pop());   
    
    // getche(); // commented out because doesn't exist on Linux systems, non-standard, cannot compile with this on Linux
    return 0;
}

