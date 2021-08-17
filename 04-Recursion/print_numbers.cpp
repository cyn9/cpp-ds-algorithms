#include <iostream>

// Ascending order:
void printA(const int &n) { 
    if (n == 1) { std::cout << n << " "; }
    else {
        printA(n-1);
        std::cout << n << " ";
    }
}
// Descending order: 
void printD(const int &n) { 
    if (n == 1) { std::cout << n << " "; }
    else {
        std::cout << n << " ";
        printD(n-1);
    }
}

int main() {
    int number {0};

    std::cout << "Enter a number >> ";
    std::cin >> number;

    printA(number);
    std::cout << '\n';

    printD(number);
    std::cout << '\n';
    return 0;
}
