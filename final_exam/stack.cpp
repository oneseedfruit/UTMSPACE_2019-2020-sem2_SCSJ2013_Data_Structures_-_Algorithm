// SCSJ 2013 - DATA Structures And Algorithms
// Practical Exam
// Semester 20192020 - 02
// Question 3 - stack.cpp
// Student detail
// Name: Randy Tan Shaoxian	
// Matric No.: SX180357CSJS04

#include <iostream>
#include <conio.h> // Marked line, commented out and back again because I'm on Linux, can't compile with non-standard headers
#include <string.h> 

using namespace std;

#define MAXSTACK 8 // Changed to 8 to allow the push() function below to show error message

class Stack
{
    private:
        int top;
        char data[MAXSTACK];              
    
    public:
        Stack();
        bool isFull();
        bool isEmpty();        
        void push(char);   
        char pop();
        char getTop();
};

Stack::Stack()
{
    top = -1;               
}

bool Stack::isFull()
{
    return (top == (MAXSTACK - 1));
}

bool Stack::isEmpty()
{
    return (top == (-1));
}

// Question 3a
// Complete the push() method below
// that able to update the index for top, 
// put the new item at the top of stack. 
// Print the pushed value at the top of stack.  
// You are also required to test whether the satck is full or not
//    
void Stack::push(char item)
{   // answer here
	
	if (isFull()) 
    {   
		cout << "\nCannot push " << item << " - stack is full";
		return; // Just exit the function if stack is full, after showing the message above
	}	
	
	// If the stack is not full, the following lines will run
	++top;
	data[top] = item;
	cout << item; // or cout << data[top]; same thing
}

char Stack::pop()
{
    if (!isEmpty())     
    {
        char item = data[top];
        top--;
        return item; // Having return only in an if block doesn't guarantee that the function returns,
	}

	return -1; // Must return something, because function has a return type of char
	// return -1 to signify that stack is empty, 
	// as there is no actual negative ASCII character code so it can mean an invalid return
}

char Stack::getTop()
{ return data[top];
}

int main()
{
	Stack aStack;
	   
    // Push data S P A C E C A R S to the stack respectively
	// print data at the top of the stack after every insertion 
	// The expected output : Pushed values : SPACECAR
	//                       Cannot push S -  stack is full 
	cout << "Pushed values : " ;
	aStack.push('S');
	aStack.push('P');
	aStack.push('A');
	aStack.push('C');
	aStack.push('E');
	aStack.push('C');
	aStack.push('A');
	aStack.push('R');
	aStack.push('S');
	cout << endl;
	
	cout << "Popped values : " ; 	
    // Question 3b
	// Write codes to pop all data in the stack 
	// and print the popped value respectively
	// The expected output : Popped values : RACECAPS
	
	//  Answer here
	// For as long as aStack is not empty, pop() the next item in aStack
	// and show each of them in the standard output stream
	for (; !aStack.isEmpty(); cout << aStack.pop())	{ }	
	cout << "\n";
	 

   	getche(); // Marked line, commented out and back again because I'm on Linux, can't compile with non-standard functions
   	return 0;
}
