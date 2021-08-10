#include <iostream>
#include <cstring>

class Test {
    private:
        int value;
        char* name;
    
    public:
        // Default no-arg constructor:
        Test() = default;

        // Two-args constructor:
        Test(char* name, int value) {
            this->value = value;

            // Deep copy the char array name to make sure of
            // obtaining the copy of the array instead of only 
            // copying the array address.
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }

        // Copy constructor:
        Test(const Test &source) {
            this->value = source.value;

            this->name = new char[strlen(source.name) + 1];
            strcpy(this->name, source.name);
        }

        inline void display() const { 
            std::cout << "Value: " << value << ", Name : " << name << '\n';
        }

        inline void changeName() { this->name[0] = 'X'; }
};

int main() {
    // Testing deep copy (for char array modification):
    char myString[] {"abcd"};

    Test t1 {myString, 20};
    std::cout << "t1: ";
    t1.display();

    // Modify array text:
    myString[3] = 'x';
    Test t2 {myString, 400};
    std::cout << "t2: ";
    t2.display();

    std::cout << '\n';
    std::cout << "t1: ";
    t1.display();

    std::cout << '\n';

    // Testing deep copy (for object copying):
    char foo[] {"ABCD"};
    Test t5 {foo, 5};
    std::cout << "t5: ";
    t5.display();

    // Invoke copying from object t5 to create a new object t6:
    Test t6 {t5};

    // Change the character in the zeroth index. The
    // change in t6 will reflect to t5 as well due to shallow copying.
    // Shallow copy is implemented by default. Copy constructor has 
    // been implemented to attain deep copy.
    t6.changeName(); 
    
    std::cout << "Changing array 0th index in array 'name':\n";
    std::cout << "t5: ";
    t5.display();
    std::cout << "t6: ";
    t6.display();

    return 0;
}
