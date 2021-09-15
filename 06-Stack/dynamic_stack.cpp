#include <iostream>

template<typename T>
class Stack {
    private:
        std::size_t m_capacity;
        std::size_t m_currentIndex;
        T *m_data;
    
    public:
        Stack() : m_capacity {1}, m_currentIndex {0} {
            this->m_data = new T[m_capacity];
        }

        ~Stack() { delete[] m_data; }

    public:
        void push(T value) {
            if (m_currentIndex == m_capacity) {
                std::cout << "Stack is full. Doubling the stack size.\n";

                T* newArray = new T[m_capacity];

                for (std::size_t i = 0; i < m_capacity; ++i) {
                    newArray[i] = m_data[i];
                }

                this->m_capacity *= 2;

                delete[] m_data;
                m_data = newArray;
            }

            m_data[m_currentIndex++] = value;
        }
        
        T pop() {
            if (this->is_empty()) {
                std::cout << "ERROR: Cannot perform pop. Stack underflow.\n";
                std::cout << "Returning -1 instead.\n";
                return -1;
            }
            else {
                return this->m_data[m_currentIndex--]; 
            }
        }
        
        T top() const {
            if (this->is_empty()) {
                std::cout << "Stack is empty. No top value in the stack.\n";
                std::cout << "Returning -1 instead.\n";
                return -1;
            }
            else {
                return this->m_data[m_currentIndex-1]; 
            }
        }

        std::size_t size()     const { return this->m_currentIndex; }
        std::size_t capacity() const { return this->m_capacity; }
        bool is_empty()        const { return this->m_currentIndex == 0; }

        void reserve(std::size_t capacity) {
            this->m_capacity = capacity;
        }

        void print() const {
            std::cout << "Stack content >> ";
            if (this->is_empty()) { std::cout << "Empty."; }

            for (std::size_t i = 0; i < m_currentIndex; ++i)
                std::cout << m_data[i] << ' ';
            
            std::cout << '\n';
        }
};

int main() {
    Stack<float> s;
    s.reserve(3);
    std::cout << "Stack capacity: " << s.capacity() << '\n';
    s.push(2.85f);
    std::cout << "Stack capacity: " << s.capacity() << '\n';
    s.push(7.75f);
    std::cout << "Stack capacity: " << s.capacity() << '\n';
    s.push(10.3f);
    std::cout << "Stack capacity: " << s.capacity() << '\n';
    s.push(0.0f);
    std::cout << "Stack capacity: " << s.capacity() << '\n';
    s.push(45.55f);
    std::cout << "Stack capacity: " << s.capacity() << '\n';

    s.print();

    return 0;
}
