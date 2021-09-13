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

template<typename T>
Node<T>* merge(Node<T>* list1, Node<T>* list2) {
    // Check if lists are empty:
    if (list1 == nullptr) { return list2; }
    if (list2 == nullptr) { return list1; }

    Node<T>* fH = nullptr; // Final head pointer.
    Node<T>* fT = nullptr; // Final tail pointer (for connections only).

    // Determine the smallest element in the final linked list:
    if ((list1->data) < (list2->data)) {
        fH = list1;
        list1 = list1->next;
    }
    else {
        fH = list2;
        list2 = list2->next;
    }
    
    fT = fH; // Initially can be same pointer because it does not matter.

    // Iterate until one of the linked lists reaches to nullptr:
    while (list1 && list2) {
        if (list1->data < list2->data) {
            fT->next = list1;
            list1 = list1->next;
        }
        else {
            fT->next = list2;
            list2 = list2->next;
        }

        fT = fT->next;
    }

    // Check which list reached the end:
    if (list1 != nullptr) {
        fT->next = list1;
    }
    else {
        fT->next = list2;
    }

    return fH;
}

int main() {
    std::cout << "Enter sorted linked lists:\n";
    std::cout << "Creating linked list 1 >> ";
    Node<int>* list1 = create<int>();

    std::cout << "Creating linked list 2 >> ";
    Node<int>* list2 = create<int>();

    std::cout << '\n';
    print(list1);
    print(list2);

    list1 = merge(list1, list2);
    print(list1);

    return 0;
}
