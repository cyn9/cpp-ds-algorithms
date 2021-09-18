#include <iostream>

#pragma pack(push, 1)
template<typename T>
struct Queue {
    T* data;
    std::size_t frontIndex;
    std::size_t nextIndex;
    std::size_t queue_size;
    std::size_t capacity;

    Queue() : Queue(1) {}
    Queue(std::size_t capacity) {
        this->capacity = capacity;
        data = new T[capacity];

        nextIndex = 0;
        frontIndex = -1;
        queue_size = 0;
    }

    std::size_t size() const { return queue_size; }
    bool is_empty() const { return (queue_size == 0); }

    void push(T val) {
        if (queue_size == capacity) {
            std::cout << "Queue is full. Cannot push data.\n";
            return;
        }

        data[nextIndex] = val;
        nextIndex = (nextIndex + 1) % capacity; // Move circularly.

        if (is_empty()) {
            frontIndex = 0;
        }

        queue_size++;
    }

    T front() const { 
        if (is_empty()) {
            std::cout << "Queue is empty.\n";
            return 0;
        }

        return data[frontIndex];
    }

    void pop() {
        if (is_empty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        queue_size--;

        // Reset variables
        if (queue_size == 0) {
            frontIndex = -1;
            nextIndex = 0;
        }
    }
};
#pragma pack(pop)

int main() {
    Queue<int> q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    std::cout << "Front element: " << q.front() << '\n';
    q.pop();
    q.pop();
    q.pop();

    std::cout << "Front element: " << q.front() << '\n';
    std::cout << "Queue size: " << q.size() << '\n';

    std::cout << std::boolalpha;
    std::cout << "Queue is empty? " << q.is_empty() << '\n';

    q.push(60);
    q.push(70);
    q.pop();
    q.pop();

    std::cout << "Front element: " << q.front() << '\n';
    std::cout << "Queue size: " << q.size() << '\n';

    std::cout << sizeof(Queue<int>) << '\n';

    return 0;
}
