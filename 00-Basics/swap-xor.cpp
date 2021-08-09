// Swap two integers using XOR.
// Can also be done with:
// void std::swap(T& a, T& b);
#include <iostream>

int main() {
    int a {0};
    int b {0};
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    
    std::cout << "Before swapping: ";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    a = a^b;
    b = a^b;
    a = a^b;
    
    std::cout << "After swapping: ";
    std::cout << "a = " << a << ", b = " << b << std::endl; 

    return 0;
}
