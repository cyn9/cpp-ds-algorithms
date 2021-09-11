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
Node<T>* createFwd();

template<typename T>
Node<T>* createRev();

int main() {
    // Node<int>* n1 = createFwd<int>(); // Head of node n1
    Node<int>* n2 = createRev<int>(); // Head of node n2

    // std::cout << "n1 >> ";
    // print(n1);

    std::cout << "n2 >> ";
    print(n2);

    return 0;
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

// Take input from the user:
// Create a linked list in forward direction:
template<typename T>
Node<T>* createFwd() {
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

// Take input from the user:
// Create a linked list in reverse direction:
template<typename T>
Node<T>* createRev() {
    T data;
    std::cout << "Enter data >> ";
    std::cin >> data;

    Node<T>* head = nullptr; // LL is initially empty.

    while (data != -1) {
        Node<T>* n = new Node<T>(data);

        // Check if n is the first element:
        if (head == nullptr) {
            head = n;
        }
        else {
            // If there are elements present in the LL:
            n->next = head; // Connect the first to the new element.
            head = n; // Update the head node.
        }

        std::cout << "Enter data >> ";
        std::cin >> data;
    }

    return head;
}
