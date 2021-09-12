#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node() = default;
    Node(T data) : data{data}, next{nullptr} {}
};

// Take input from the user:
// Create a linked list in forward direction:
template<typename T>
Node<T>* create() {
    T data;
    std::cout << "Enter data >> ";
    std::cin >> data;

    Node<T>* head = nullptr; // LL is initially empty.
    Node<T>* tail = nullptr; // No elements present in the LL.

    while (data != -1) {
        Node<T>* n = new Node<T>(data);

        // Check if n is the first element:
        if (head == nullptr) {
            head = n;
            tail = n;
        }
        else {
            // If there are elements present in the LL:
            tail->next = n; // Connect the last to the new element.
            tail = n; // Update the tail node.
        }

        std::cout << "Enter data >> ";
        std::cin >> data;
    }

    return head;
}

template<typename T>
void print(Node<T>* nodePtr) {
    // Iterate over a temp pointer to always have access
    // to the first element of the linked list.
    Node<T>* temp = nodePtr;

    std::cout << "Printing linked list >> ";
    while (temp != nullptr) {
        std::cout << temp->data << "-->";
        temp = temp->next;
    }
    
    std::cout << "NULL" << '\n';
}

// Removes kth node from the end of the linked list.
// T = O(n), S = O(1)
template<typename T>
Node<T>* removeNode(Node<T>* nodePtr, const int k) {
    // Test an invalid index:
    if (k <= 0) {
        std::cout << "Error: Index out of bounds.\n";
        return nodePtr;
    }

    // Check if the linked list is empty:
    if (nodePtr == nullptr) { return nodePtr; }

    Node<T>* head = nodePtr; // Actual head pointer of the LL.
    Node<T>* ptr1 = nodePtr; // Dummy pointer
    Node<T>* ptr2 = nodePtr; // Dummy pointer

    // Maintain "k" distance between two pointers.
    // Change ptr2 by k positions:
    for (auto i = 0; i < k; i++) {
        ptr2 = ptr2->next;
    }

    // Special case: Remove first (head) element in the LL:
    // Occurs if k is equal to the length of the LL.
    if (ptr2 == nullptr) {
        Node<T>* newHead = ptr1->next;
        
        ptr1 = nullptr;
        delete ptr1;

        return newHead;
    }

    // Iterate until ptr2's next reaches the nullptr (end of the LL):
    while (ptr2->next != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    Node<T>* temp = ptr1->next; // Store the address of the node to be deleted.
    ptr1->next = (ptr1->next)->next;

    temp->next = nullptr;
    delete temp;

    return head;
}

int main() {
    int index {0};

    Node<int>* n = create<int>();
    print(n);

    std::cout << "Enter an index >> ";
    std::cin >> index;

    n = removeNode(n, index);
    print(n);

    return 0;
}
