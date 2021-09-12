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

// Delete node:
template<typename T>
Node<T>* erase(Node<T>* nodePtr, const int index) {
    // Check if the linked list is empty:
    if (nodePtr == nullptr) {
        std::cout << "Empty linked list.\n";
        return nodePtr;
    }

    // Check the invalid index.
    if (index < 0) {
        std::cout << "Invalid index.\n";
        return nodePtr;
    }

    Node<T>* head = nodePtr; // Store actual head pointer to return.
    
    // Special case: Delete the head of the linked list.
    if (index == 0 && nodePtr != nullptr) {
        Node<T>* newHead = nodePtr->next;
        
        nodePtr->next = nullptr;
        delete nodePtr;

        return newHead;
    }

    // Intermedite indices:
    int i {1}; // Count the index of the current head pointer.
    
    // Iterate (i-1) time to get previous position of the node
    // to be deleted.
    while (i < index && nodePtr != nullptr) {
        nodePtr = nodePtr->next;
        i++;
    }

    if ((nodePtr != nullptr) && (nodePtr->next) != nullptr) {
        Node<T>* temp = nodePtr->next;
        
        nodePtr->next = (nodePtr->next)->next;
        
        temp->next = nullptr;
        delete temp;

        return head;
    }

    return head;
}

int main() {
    Node<int>* n = create<int>();
    print(n);

    int pos {0};

    std::cout << "Position >> ";
    std::cin >> pos;

    n = erase(n, pos);
    print(n);

    return 0;
}
