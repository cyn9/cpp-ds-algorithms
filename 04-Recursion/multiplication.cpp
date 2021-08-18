#include <iostream>
#include <algorithm>

int multiply(int, int);

int main() {
    int m {0};
    int n {0};

    std::cout << "Enter m >> ";
    std::cin >> m;

    std::cout << "Enter n >> ";
    std::cin >> n;

    int result = multiply(m, n);
    std::cout << m << " x " << n << " = " << result << '\n';
    return 0;
}

int multiply(int m, int n) {
    // Reduce the number of recursive calls by swapping 
    // the numbers (get smallest as number "n").
    if (m < n) { std::swap(m, n); }

    // Base case:
    if (n == 0) { return 0; }

    return m + multiply(m, n-1);
}
