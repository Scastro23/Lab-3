// Samuel Castro
// Lab 3 
// SP2024
/* Description: A stack is an abstract data type in which elements are added and removed
from only one end; a “last in, first out” structure. This stack must be implemented as a
linked structure (ie using pointers).*/

#include <iostream>

template <class T>
class Stack {
private:
    // Node structure
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {} // Constructor
    };

    Node* topNode; // Pointer to the top node

public:
    // Constructor
    Stack() : topNode(nullptr) {}

    // Destructor to deallocate memory for all nodes when stack is destroyed
    ~Stack() {
        while (!IsEmpty()) {
            Pop(); // Pop until stack is empty
        }
    }

    // Function check if stack is empty
    bool IsEmpty() const {
        return topNode == nullptr; // If topNode is nullptr, stack empty
    }

    // Function to add a new item to the top
    void Push(const T& item) {
        Node* newNode = new Node(item); // Create a new node with the given data
        newNode->next = topNode;
        topNode = newNode;
    }

    // Function to remove the top item
    void Pop() {
        if (IsEmpty()) {
            std::cerr << "Error: Stack is empty. Cannot pop.\n"; // Print error message
            return;
        }
        Node* temp = topNode; // Store the address
        topNode = topNode->next; // Move topNode to next node
        delete temp; // Deallocate memory for old top node
    }

    // Function to get the top item
    T Top() const {
        if (IsEmpty()) {
            std::cerr << "Error: Stack is empty. Cannot get top item.\n"; // Print error message
            exit(1); // Exit program
        }
        return topNode->data;
    }
};

int main() {
    Stack<int> stack; // Create stack

    stack.Push(1); // Push elements onto stack
    stack.Push(2);
    stack.Push(3);

    // Pop and print elements from the stack
    while (!stack.IsEmpty()) {
        std::cout << stack.Top() << " "; // Print the top element
        stack.Pop(); // Pop the top element
    }
    std::cout << std::endl;

    return 0;
}
