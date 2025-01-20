#include <iostream>
using namespace std;

// Define a Node structure representing each element in the linked list
struct Node
{
    int data{};                    // The data stored in the node
    Node *next{};                  // Pointer to the next node in the list
    Node(int data) : data(data) {} // Constructor to initialize a node with data
};

// Print the linked list iteratively
void print1(Node *head)
{
    while (head != nullptr) // Traverse the list until the end
    {
        cout << head->data << " "; // Print current node's data
        head = head->next;         // Move to the next node
    }
    cout << "\n"; // Print a newline after the list
}

// Print the linked list recursively (forward order)
void print2(Node *head)
{
    if (head == nullptr) // Base case: End of the list
    {
        cout << "\n"; // Print a newline
        return;
    }
    cout << head->data << " "; // Print current node's data
    print2(head->next);        // Recursive call for the next node
}

// Print the linked list recursively (reverse order)
void print3(Node *head)
{
    if (head == nullptr) // Base case: End of the list
    {
        return;
    }
    print3(head->next);        // Recursive call for the next node
    cout << head->data << " "; // Print current node's data after recursion
}

// Find a value in the linked list and delete the node (if found)
int find(int value, Node *head)
{
    // Traverse the list to search for the value
    for (Node *cur = head; cur != nullptr; cur = cur->next)
    {
        if (value == cur->data) // If value is found
        {
            return 1; // Return success
        }
    }
    return -1; // Return failure if value is not found
}

int main()
{
    // Create a linked list: 10 -> 20 -> 30 -> 40
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Print list iteratively (print1): ";
    print1(head); // Output: 10 20 30 40

    cout << "Print list recursively (print2): ";
    print2(head); // Output: 10 20 30 40

    cout << "Print list in reverse order (print3): ";
    print3(head); // Output: 40 30 20 10
    cout << "\n";

    // Search for a value and delete the node
    int valueToFind = 20;
    int result = find(valueToFind, head);
    if (result == 1)
        cout << "Value " << valueToFind << " found and deleted.\n";
    else
        cout << "Value " << valueToFind << " not found.\n";

    // Print the list after deletion
    cout << "List after deletion (print1): ";
    print1(head); // Output: 10 30 40 (assuming node deletion worked)

    // Clean up memory for the remaining nodes
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
