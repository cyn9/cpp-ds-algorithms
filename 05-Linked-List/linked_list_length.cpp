#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node() = default;
    Node(T data) : data{data}, next{nullptr} {}
};

template<typename T>
void print(Node<T> *);

template<typename T>
Node<T>* create();

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
std::size_t length(Node<T>* node) {
    std::size_t len {0};

    Node<T>* temp = node; // Head node here.

    // If empty, return 0.
    if (temp == nullptr) { return 0; }

    // while (temp) equivalent to while (temp != nullptr)
    while (temp) {
        temp = temp->next;
        len++;
    }
    
    return len;
}

int main() {
    Node<int>* n = create<int>();

    print(n);
    std::cout << "Length of the linked list is " << length(n) << '\n';

    return 0;
}
