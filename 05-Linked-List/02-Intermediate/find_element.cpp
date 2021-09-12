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

// T = O(n), S = O(1)
template<typename T>
bool is_present(Node<T>* head, const T &data) {
    // Temporary node pointer to represent "current pointer" for iteration.
    Node<T>* temp = head;
    std::size_t index {0};

    while (temp != nullptr) {
        if (temp->data == data) {
            std::cout << "Data " << data << " found at index " << index << ".\n";
            return true;
        }

        temp = temp->next;
        index++;
    }

    std::cout << "Data " << data << " not found.\n";
    return false;
}

int main() {
    Node<int>* n = create<int>();
    int value {0};

    std::cout << "Enter a number >> ";
    std::cin >> value;

    [[maybe_unused]] bool b = is_present(n, value);

    return 0;
}
