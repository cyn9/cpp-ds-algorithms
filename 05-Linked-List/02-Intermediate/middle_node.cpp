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

// Implements slow&fast pointer approach:
// T = O(n)
template<typename T>
Node<T>* middle(Node<T>* head) {
    // Check if the linked list is empty:
    if (head == nullptr) { return head; }

    Node<T>* slow = head;
    Node<T>* fast = head->next;

    int numOfIterations {0};

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = (fast->next)->next;

        numOfIterations++;
    }

    // Return for even and odd number of elements:
    if (fast == nullptr)
        return slow; // Odd number of elements
    
    return slow->next; // Even number of elements
}

int main() {
    Node<int>* n = create<int>();

    Node<int>* mid = middle(n);

    if (mid != nullptr)
        std::cout << "Data at mid: " << mid->data << '\n';
    else
        std::cout << "Empty list.\n";

    return 0;
}
