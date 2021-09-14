#include <iostream>

template<typename T>
class Stack {
    private:
        std::size_t m_size;
        std::size_t m_currentIndex;
        T *m_data;
    
    public:
        Stack() : Stack(1) {}
        Stack(std::size_t sz) : m_size {sz}, m_currentIndex {0} {
            m_data = new T[sz];
        }
        ~Stack() { delete[] m_data; }

    public:
        void push(T value) {
            if (m_currentIndex == m_size)
                std::cout << "ERROR: Cannot push element " << value << ". Stack overflow.\n";
            else
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

        std::size_t size()      const { return this->m_currentIndex; }
        std::size_t capacity()  const { return this->m_size; }
        bool is_empty()         const { return this->m_currentIndex == 0; }

        void print() const {
            std::cout << "Stack content >> ";
            if (this->is_empty()) { std::cout << "Empty."; }

            for (std::size_t i = 0; i < m_currentIndex; ++i)
                std::cout << m_data[i] << ' ';
            
            std::cout << '\n';
        }
};

int main() {
    Stack<int> s(10);
    s.print();
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.print();

    std::cout << "Stack size is " << s.size() << '\n';
    std::cout << "Stack capacity is " << s.capacity() << '\n';

    std::cout << "\nTesting stack underflow: \n";
    for (std::size_t i = 0; i < 4; ++i) {
        std::cout << "Popping element: " << s.top() << '\n';
        s.pop();
    }
    s.print();

    std::cout << "\nTesting stack overflow: \n";
    for (auto i = 0; i < 11; ++i) {
        std::cout << "Pushing element: " << i << '\n';
        s.push(i);
    }
    s.print();

    return 0;
}
