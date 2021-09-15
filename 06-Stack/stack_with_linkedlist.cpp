#include <iostream>

template<typename T>
struct Node {
    Node<T>* next;
    T data;
        
    Node() : Node(0) {}
    Node(T data) : data {data} { this->next = nullptr; }    
};

// Stack implementation using linked list:
// Time complexity of the functions: T = O(1)
template<typename T>
class Stack {
    private:
        Node<T>* head;
        std::size_t m_size;
    
    public:
        Stack() : head {nullptr}, m_size {0} {}

    public:
        std::size_t size() const { return this->m_size; }
        bool is_empty() const { return (this->m_size == 0); }

        void push(const T data) {
            Node<T>* temp = new Node<T>(data);
            temp->next = head;
            head = temp;
            this->m_size++;
        }

        void pop() {
            if (this->m_size == 0) {
                std::cout << "Stack is empty. Cannot pop any value.\n";
            }
            else {
                Node<T>* temp = head;
                head = head->next;

                temp->next = nullptr;
                delete temp;
                temp = nullptr;

                this->m_size--;
            }
        }

        T top() const {
            if (this->m_size == 0) {
                std::cout << "Stack is empty. Returning zero.\n";
                return 0;
            }
            else {
                return this->head->data;
            }
        }

        void print() const {
            Node<T>* temp = this->head;

            std::cout << "Stack content >> ";
            while (temp) {
                std::cout << temp->data << ' ';
                temp = temp->next;
            }
            std::cout << '\n';
        }
};

int main() {
    std::cout << std::boolalpha;

    Stack<double> s;
    std::cout << "Stack size: " << s.size() << '\n';
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    std::cout << "Stack size: " << s.size() << '\n';
    std::cout << "Is Stack empty? " << s.is_empty() << '\n';

    std::cout << "Top element = " << s.top() << '\n';
    s.pop();
    std::cout << "Top element = " << s.top() << '\n';
    s.pop();
    std::cout << "Top element = " << s.top() << '\n';
    s.pop();
    s.pop();

    std::cout << "Is Stack empty? " << s.is_empty() << '\n';

    return 0;
}