#include <iostream>

int sum(const int &);

int main() {
    int number {0};

    std::cout << "Enter a number >> ";
    std::cin >> number;

    std::cout << "Sum of digits = " << sum(number) << '\n';
    return 0;
}

int sum(const int &N) {
    if (N > 0 && N < 10) { return N; }
    else                 { return (N % 10) + sum(N/10); }
}
