#include <iostream>

template <typename T>
struct Node {
    Node<T>* next;
    T data;
    
    Node() : Node(0) {}
    Node(T data) : next{nullptr}, data{data} {}
};

template <typename T>
struct Queue {
    Node<T>* head;
    Node<T>* tail;
    std::size_t queue_size;

    Queue() : head{nullptr}, tail{nullptr}, queue_size{0} {}

    std::size_t size() const { return this->queue_size; }
    bool is_empty()    const { return (this->size() == 0); }
    
    T front() const { 
        if (is_empty()) {
            std::cout << "Empty queue.\n";
            return 0;
        }

        return head->data; 
    }

    void push(const T data) {
        Node<T>* temp = new Node<T>(data);
        
        if (is_empty()) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp; // Connection
            tail = temp; // Update the pointer
        }

        this->queue_size++;
    }

    void pop() {
        if (is_empty()) {
            std::cout << "Empty queue. Cannot pop.\n";
            return;
        }
        else {
            Node<T>* prev_head = head;
            head = head->next;

            prev_head->next = nullptr;
            delete prev_head;
            prev_head = nullptr;
            
            this->queue_size--;
        }
    }
};

int main() {
    std::cout << std::boolalpha;

    Queue<float> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    std::cout << "Queue size: " << q.size() << '\n';
    std::cout << "Front element: " << q.front() << "\n\n";

    q.push(50);
    q.pop();
    q.push(60);
    q.pop();
    q.push(70);

    std::cout << "Queue size: " << q.size() << '\n';
    std::cout << "Front element: " << q.front() << "\n\n";
    std::cout << "Queue is empty? " << q.is_empty() << '\n';

    q.push(-40);
    q.push(-50);
    q.pop();
    q.pop();
    q.pop();

    std::cout << "Queue size: " << q.size() << '\n';
    std::cout << "Front element: " << q.front() << '\n';

    // Print queue content as well:
    std::cout << "Queue content >> ";
    while (!q.is_empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << '\n';

    std::cout << "Queue is empty? " << q.is_empty() << '\n';

    return 0;
}
