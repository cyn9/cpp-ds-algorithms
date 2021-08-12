#include <iostream>
#include <exception>

class ArrayOutOfBoundsException : public std::exception {
    public:
        virtual const char *what() const noexcept {
            return "Array out of bounds: Invalid index.";
        }
};

class DynamicArray {
    private:
        int* m_data;
        int m_nextIndex;
        int m_capacity;
    
    public:
        DynamicArray() : DynamicArray(1) {}
        DynamicArray(int capacity) : m_capacity {capacity} {
            m_nextIndex = 0;
            m_data = new int[capacity];
            m_data[m_nextIndex] = 0;
        }

        DynamicArray(const DynamicArray& source) {
            this->m_nextIndex = source.m_nextIndex;
            this->m_capacity = source.m_capacity;

            this->m_data = new int[this->m_capacity];
            for (int i = 0; i < this->m_nextIndex; ++i)
                this->m_data[i] = source.m_data[i];
        }

        ~DynamicArray() { delete[] m_data; }

        // Overloading operators:
        DynamicArray& operator=(const DynamicArray& source) {
            this->m_nextIndex = source.m_nextIndex;
            this->m_capacity = source.m_capacity;

            this->m_data = new int[this->m_capacity];
            for (int i = 0; i < this->m_nextIndex; ++i)
                this->m_data[i] = source.m_data[i];
            
            return *this;
        }

        // Class methods:
        void insert(int e) {
            if (m_nextIndex == m_capacity) {
                std::cout << "Doubling capacity...\n";
                int* temp = new int[2 * m_capacity];

                for (int i = 0; i < m_capacity; ++i)
                    temp[i] = m_data[i];

                delete[] m_data;
                m_data = temp;

                m_capacity *= 2;

                // Add element after doubling the capacity.
                m_data[m_nextIndex++] = e;
            }
            else {
                m_data[m_nextIndex++] = e;
            }
        }

        void insert(int e, int index) {
            if (index < m_nextIndex)
                m_data[index] = e;
            else if (index == m_nextIndex)
                insert(e);
            else
                throw ArrayOutOfBoundsException();
        }

        int get(int index) const {
            // Bound check:
            if (index >= 0 && index < m_capacity) {
                return m_data[index];
            }
            else
                throw ArrayOutOfBoundsException();
        }

        void print() const {
            std::cout << "Content of the array: ";

            for (int i = 0; i < m_nextIndex; ++i)
                std::cout << m_data[i] << ' ';
            
            std::cout << '\n';
        }

        inline int capacity()     const { return m_capacity; }
        inline int getNextIndex() const { return m_nextIndex; }
};

int main() {
    // Testing insertion:
    DynamicArray arr1(1);

    arr1.insert(10);
    arr1.insert(20);
    arr1.insert(30);
    arr1.insert(40);
    arr1.insert(50);

    std::cout << "\narr1: ";
    arr1.print();

    // Testing copying:
    DynamicArray arr2 {arr1};
    std::cout << "arr2: ";
    arr2.print();

    arr1.insert(100, 0);
    std::cout << "\narr1: ";
    arr1.print();
    std::cout << "arr2: ";
    arr2.print();

    // Testing = operator:
    arr2.insert(100, 2);
    DynamicArray arr3;
    arr3 = arr2;

    std::cout << "\narr2: ";
    arr2.print();
    std::cout << "arr3: ";
    arr3.print();

    // Try to access an element that's out of bounds:
    std::cout << arr3.get(100) << '\n';

    return 0;
}
