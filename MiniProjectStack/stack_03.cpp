// stack_03.cpp         
#include <iostream>
#include <conio.h>

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
    
    getche();
    return 0;
}

