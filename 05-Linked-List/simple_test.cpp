#include <iostream>

class Node {
    private:
        int m_data;
        Node* m_next;
    
    public:
        Node() = default;
        Node(int data) : m_data{data}, m_next{nullptr} {}

        int getData() const { return this->m_data; }

        Node* getNext() const { 
            return this->m_next;
        }

        void setNext(Node* nextPtr) {
            this->m_next = nextPtr;
        }
};

void print(Node *);

int main() {
    // Create nodes statically:
    Node n1(1);
    Node n2(2);
    Node* head = &n1;   // Address of the first element in the LL

    n1.setNext(&n2);    // Making a connection between nodes n1 and n2.
    std::cout << n1.getData() << ", ";
    std::cout << n2.getData() << '\n';

    // Also can print the first element using head pointer:
    std::cout << head->getData() << '\n';

    // Create nodes dynamically:
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n3->setNext(n4); // Connect n3 and n4.

    // Print n3 and n4 data:
    std::cout << "n3 and n4 >> " << n3->getData() << "-->" 
                                 << n4->getData() << '\n';

    delete n3;
    delete n4;

    // Example 2: LL of 5 nodes:
    Node m1(10);
    Node m2(20);
    Node m3(30);
    Node m4(40);
    Node m5(50);
    Node* head_m = &m1; // Head pointer to m1

    m1.setNext(&m2); // Connect m1 and m2
    m2.setNext(&m3); // Connect m2 and m3
    m3.setNext(&m4); // Connect m3 and m4
    m4.setNext(&m5); // Connect m4 and m5

    // Print the content of the linked list m1...5:
    print(head_m);

    return 0;
}

void print(Node* nodePtr) {
    // Iterate over a temp pointer to always have access
    // to the first element of the linked list.
    Node* temp = nodePtr;

    std::cout << "Printing linked list >> ";
    while (temp != nullptr) {
        std::cout << temp->getData() << "-->";
        temp = temp->getNext();
    }
    
    std::cout << "NULL" << '\n';
}
