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

// T = O(n), S = O(1)
template<typename T>
Node<T>* reverse(Node<T>* head) {
    // Check if the list is empty:
    if (head == nullptr) { return head; }

    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* n = curr->next;

    while (curr != nullptr) {
        n = curr->next;     // Next of the current node.

        curr->next = prev;  // Reverse the connection direction.
        prev = curr;        // Shift pointers to right.
        curr = n;           // Shift pointers to right.
    }

    return prev; // Return the new "head" of the linked list.
}

int main() {
    Node<int>* n = create<int>();
    print(n);

    Node<int>* rev = reverse(n);
    print(rev);
    
    return 0;
}
