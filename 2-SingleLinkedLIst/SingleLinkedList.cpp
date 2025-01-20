#include "Node.cpp" // Include the Node class or header file

// Class representing a singly linked list
class SingleLinkedList
{
private:
    Node *head{};   // Pointer to the first node in the list
    Node *tail{};   // Pointer to the last node in the list
    int length = 0; // Number of nodes in the list

public:
    // Constructor: Initializes an empty linked list
    SingleLinkedList()
    {
        head = tail = nullptr; // Both head and tail are null initially
    }

    // Destructor: Cleans up allocated memory (for head and tail)
    ~SingleLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next; // Save the next node
            delete current;             // Delete the current node
            current = next;             // Move to the next node
        }
        head = tail = nullptr; // Set head and tail to nullptr for safety
    }

    // Function to print all nodes in the linked list
    void print()
    {
        for (Node *cur = head; cur != nullptr; cur = cur->next) // Traverse the list
        {
            cout << cur->data << " "; // Print the data of each node
        }

        cout << endl; // Newline after the list
        // Print the details of head, tail, and the list length
        cout << "head = " << head->data << ", tail = " << tail->data << ", Length is : " << length << endl;
    }

    // Function to insert a new node at the end of the list
    void insert_end(int value)
    {
        Node *temp = new Node(value); // Create a new node with the given value
        if (!head)                    // If the list is empty
        {
            head = tail = temp; // The new node is both the head and tail
        }
        else
        {
            tail->next = temp; // Link the new node to the end of the list
            tail = temp;       // Update the tail to the new node
        }
        length++; // Increment the length of the list
    }
};

// Main function to demonstrate the use of SingleLinkedList
int main()
{
    // Create a new singly linked list
    SingleLinkedList *s1 = new SingleLinkedList();

    // Insert elements at the end and print the list after each insertion
    s1->insert_end(5);
    s1->print(); // Output: 5, head = 5, tail = 5, Length is : 1

    s1->insert_end(10);
    s1->print(); // Output: 5 10, head = 5, tail = 10, Length is : 2

    s1->insert_end(15);
    s1->print(); // Output: 5 10 15, head = 5, tail = 15, Length is : 3

    // Clean up memory allocated for the linked list
    delete s1;

    return 0;
}
