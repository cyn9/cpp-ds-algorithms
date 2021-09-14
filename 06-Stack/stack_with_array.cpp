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
        void push(T value) { m_data[m_currentIndex++] = value; }
        
        T pop()                       { return this->m_data[m_currentIndex--]; }
        T top()                 const { return this->m_data[m_currentIndex-1]; }
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

    return 0;
}
