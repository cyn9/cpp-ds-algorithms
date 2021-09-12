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

template <typename T>
bool is_present(Node<T>* head, const T &data) {
    // Base case:
    if (head == nullptr) { return false; }

    // If found, return true:
    if (head->data == data) { return true; }

    // Otherwise, process the smaller problem:
    return is_present(head->next, data);
}

int main() {
    Node<int>* n = create<int>();
    int value {0};

    std::cout << "Enter a number >> ";
    std::cin >> value;

    if (is_present(n, value)) std::cout << "Found.\n";
    else                      std::cout << "Not found.\n";

    return 0;
}
