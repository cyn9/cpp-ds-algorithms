#include <iostream>
#include <iomanip>
#include <cmath>

float geometricSum(const int &);

int main() {
    int k {0};

    std::cout << "Enter k >> ";
    std::cin >> k;

    std::cout << std::setprecision(5);
    std::cout << "Result of the geometric sum = " << geometricSum(k) << '\n';
    
    return 0;
}

float geometricSum(const int &k) {
    if (k == 0) { return 1; }

    return std::pow(2.0, -k) + geometricSum(k-1);
}
