#include <iostream>

int count(const int &);

int main() {
    int number {0};

    std::cout << "Enter a number >> ";
    std::cin >> number;

    std::cout << "Number of digits in " << number << " = " << count(number) << '\n';
    return 0;
}

int count(const int &N) {
    if (N < 10 && N > 0) { return 1; }
    else                 { return 1 + count(N/10); }
}
