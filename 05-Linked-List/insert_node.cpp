#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node() = default;
    Node(T data) : data{data}, next{nullptr} {}
};

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

// Insert a node to a given index:
// nodePtr is the "head" of the linked list.
template<typename T>
Node<T>* insert(Node<T>* nodePtr, T data, const int index) {
    // Check the invalid index.
    if (index < 0) {
        std::cout << "Invalid index.\n";
        return nodePtr;
    }

    Node<T>* head = nodePtr; // Store actual head pointer to return.
    Node<T>* newNode = new Node<T>(data);
    
    // Special case: Insert to the beginning of the linked list.
    if (index == 0) {
        newNode->next = nodePtr;
        nodePtr = newNode;

        return nodePtr;
    }

    // Intermedite indices:
    int i {0}; // Count the index of the current head pointer.

    // Iterate (i-1) time to get previous position of the node
    // to be inserted.
    while (i < index && nodePtr != nullptr) {
        nodePtr = nodePtr->next;
        i++;
    }

    if (nodePtr != nullptr) {
        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }

    return head;
}

int main() {
    Node<int>* n = create<int>();
    print(n);

    int data {0};
    int pos {0};

    std::cout << "Data >> ";
    std::cin >> data;

    std::cout << "Position >> ";
    std::cin >> pos;

    n = insert(n, data, pos);
    print(n);

    return 0;
}
