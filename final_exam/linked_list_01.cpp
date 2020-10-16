// SCSJ 2013 - DATA Structures And Algorithms
// Practical Exam
// Semester 20192020 - 02
// Question 1 - linkedlist_01.cpp
// Student detail
// Name: Randy Tan Shaoxian
// Matric No.: SX180357CSJS04


#include <iostream>
#include <string>

using namespace std;

// Class definitions. //////////////////////////////////////////////////////////
class Node {
    public:
        // Nodes's Constructor
        Node(int);
                   
        // Node's member variables for node's item
        int item;
        Node* next;
};

// Node constructor implementation ///////////////////////////////////////
Node::Node(int i) {
    item = i;
}

// Print linked list content  /////////////////////
void listNode(Node* head) {
    Node* current = head;
    
    while (current) {
        cout << current->item << endl;
        current = current->next;
    }
}


// Main function //////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    Node* head = NULL;
        
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    
    // Answer question 1-a after this line     [2 Marks]
    // Declare node n3 with value equal to 30
    Node* n3 = new Node(30);
    
    // Answer question 1-b after this line     [3 Marks]
    // Print the value of every node according to the output given in the question
    cout << "Value at node 1 : " << n1->item << "\n";
    cout << "Value at node 2 : " << n2->item << "\n";
    cout << "Value at node 3 : " << n3->item << "\n";
    
    // Answer question 1-c after this line     [3 Marks]
    // Connect node pointed by n1, n2 and n3 as shown in Figure 1.3
    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    
    // print the list content
	cout << "List node start from header:" << endl;
    listNode(head);
    
    // Answer question 1-d after this line     [4 Marks] 
    // Declare node n4 with value 25 and insert n4 between node n2 and n3 
    Node* n4 = new Node(25);
    n2->next = n4;
    n4->next = n3;
    
    // print the list content
	cout << "List node start from header after node " << n4->item << " is inserted:" << endl;
    listNode(head);
    
    // Answer question 1-e after this line     [4 Marks]
    // Delete node n2 and print the requested output
    n1->next = n4; // Point n1's next to the next available node
    int n2_val = n2->item; // Store the value of the item in n2 before deleting n2
    delete n2;
    n2 = NULL;
    cout << "Node with value " << n2_val << " has been deleted.\n";
    
    // Answer question 1-f after this line     [4 Marks]
    // Delete node n1 and print the requested output
    head = n1->next; // Move head to the next available node
    int n1_val = n1->item; // Store the value of the item in n1 before deleting n1
    delete n1;
    n1 = NULL;
    cout << "Node with value " << n1_val << " has been deleted.\n";
  
    // Print Node's list start from header
    cout << "List node start from header:" << endl;
    listNode(head);
              
        
    system("PAUSE"); // Marked line, commented out and back again because I'm on Linux, can't compile with non-standard functions.
    return 0;
}
