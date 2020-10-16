// SCSJ 2013 - DATA Structures And Algorithms
// Practical Exam
// Semester 20192020 - 02
// Question 2 - linkedList_02.cpp
// Student Detail
// Name: Randy Tan Shaoxian
// Matric No.: SX180357CSJS04


#include <iostream>
#include <string>

using namespace std;

// Node class implementation. //////////////////////////////////////////////////
class Node {
    public:
        // Node's member variables for node's item
        int item;
        Node* next;

        // Nodes's Constructor
        Node(int i) {
            item = i;
            next = NULL;
        }
};

// Print linked list content 
void listNode(Node* head) {
    Node* current = head;

    while (current) {
        cout << current->item << " ";
        current = current->next;
    }

    cout << "\n\n";
}

// Delete linked list content 
void deleteAll(Node* head) {
    Node* prev;
    Node* current = head;

    while (current) {
        prev = current;
        current = current->next;
        cout << "Delete " << prev->item << "\n";
        delete prev;
        prev = NULL;
    }
}

// Main function //////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    Node* head = NULL;
    Node* current = NULL;
	// Creeting linked list with values : 1, 3, 5, 7, 9
    for (int i = 1; i <= 9; i += 2) {
        if (current == NULL) {
            current = new Node(i);
            head = current;

        } else {
            current->next = new Node(i);
            current = current->next;
        }
    }

    // Print Node's list start from header
    cout << "List original nodes start from header:\n";
    listNode(head);

    // Answer question 2-a after this line [5 Marks]
    Node *newNode = new Node(2);
    current = newNode;
    newNode->next = head->next;
    head->next = current;
    
    cout << "List nodes after node 2 is added:\n";
    listNode(head);

    // Answer question 2-b after this line [5 Marks]
    Node *findNode;
    // Start by letting findNode point to head, starting from the first node at head,
    //         for as long as there is a next node (findNode->next != NULL)
    //     AND findNode's current item does not match 3 (findNode->item != 3)
    //         move findNode to the next connected node (findNode = findNode->next)
    for (findNode = head; findNode->next != NULL && findNode->item != 3; findNode = findNode->next) {}    
    current->next = findNode->next;
    delete findNode;
    findNode = NULL;
    
    cout << "List nodes after node 3 has been deleted from the list\n";
    listNode(head);
    
    // Assigning tail pointer to point to the last node in the list
	Node* tail = head;
    while (tail!=NULL)
       tail = tail->next;
    
	// Answer question 2-c after this line [10 Marks]
    Node *detachedHead = head; // Pointer variable pointing to head 
                               // (store the node at head to be detached, for access later)                    
    head = head->next; // Move head to the next connected node
    detachedHead->next = NULL; // detachedHead is completely detached from the linked list now
    // The for loop below acts to get access to the node which is one node before tail,
    // if this is a doubly linked list, it would be tail->previous, but because this is only
    // a singly linked list, we have to iterate through the nodes, using current as access
    // we don't actually need to start by pointing current to head here, because from 2-a above,
    // and after the head = head->next line, current has already been pointing to the same node as head
    for (; current ->next != NULL; current = current->next) {}
    // once done with the for loop, current->next is now NULL, which means it is 
    // the last node at the end of the linked list    
    current->next = detachedHead; // so point current's next to the detachedHead
    tail = detachedHead; // then move tail over to the new last node at the end of the linked list
    // tail->next is NULL because detachedHead->next = NULL; above
    
    cout << "List nodes after node 1 has been moved to the end of the list\n";
    listNode(head);

    // Delete all nodes
    deleteAll(head);

    system("PAUSE"); // Marked line, commented out and back again because I'm on Linux, can't compile with non-standard functions.
    return 0;
}
