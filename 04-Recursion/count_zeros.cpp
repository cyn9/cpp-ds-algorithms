#include <iostream>
int count_zeros(const long &);

int main() {
    int number {0};

    std::cout << "Enter a number >> ";
    std::cin >> number;

    int result = count_zeros(number);
    std::cout << "Number "  << number << " has " << result << " zeros.\n";

    return 0;
}

int count_zeros(const long &number) {
    // Base case:
    if (number < 10 && number > 0) { return 0; }

    if (number % 10 == 0) { return 1 + count_zeros(number/10); }
    else                  { return     count_zeros(number/10); }
}
