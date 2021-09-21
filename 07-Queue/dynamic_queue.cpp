#include <iostream>

template<typename T>
struct Queue {
    T* data;
    std::size_t frontIndex;
    std::size_t nextIndex;
    std::size_t queue_size;
    std::size_t queue_capacity;

    Queue() : Queue(1) {}
    Queue(std::size_t queue_capacity) {
        this->queue_capacity = queue_capacity;
        data = new T[queue_capacity];

        nextIndex = 0;
        frontIndex = -1;
        queue_size = 0;
    }

    std::size_t capacity() const { return this->queue_capacity; }
    std::size_t size()     const { return this->queue_size; }
    bool is_empty()        const { return (this->queue_size == 0); }

    void push(T val) {
        if (queue_size == queue_capacity) {
            T *newArray = new T[2 * queue_capacity];
            
            unsigned j {0};
            for (std::size_t i = frontIndex; i < queue_capacity; ++i) {
                newArray[j++] = data[i];
            }

            for (std::size_t i = 0; i < frontIndex; ++i) {
                newArray[j++] = data[i];
            }

            frontIndex = 0;
            nextIndex = queue_capacity;
            queue_capacity *= 2;

            delete[] data;
            data = newArray;
        }

        data[nextIndex] = val;
        nextIndex = (nextIndex + 1) % queue_capacity; // Move circularly.

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

        frontIndex = (frontIndex + 1) % queue_capacity;
        queue_size--;

        // Reset variables
        if (queue_size == 0) {
            frontIndex = -1;
            nextIndex = 0;
        }
    }
};

int main() {
    Queue<int> q(4);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    std::cout << "Queue capacity: " << q.capacity() << '\n';
    std::cout << "Queue size: " << q.size() << '\n';
    std::cout << "Front element: " << q.front() << "\n\n";

    q.push(50);
    q.push(60);
    q.push(70);

    std::cout << "Queue capacity: " << q.capacity() << '\n';
    std::cout << "Queue size: " << q.size() << '\n';
    std::cout << "Front element: " << q.front() << "\n\n";

    q.push(80);
    q.push(90);
    q.pop();
    q.pop();
    q.pop();

    std::cout << "Queue capacity: " << q.capacity() << '\n';
    std::cout << "Queue size: " << q.size() << '\n';
    std::cout << "Front element: " << q.front() << '\n';

    return 0;
}
