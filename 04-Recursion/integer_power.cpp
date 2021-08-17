#include <iostream>

int pow(const int &, const int &);

int main() {
    int x {0};
    int a {0};
    std::cout << "Enter a number and an exponent >> ";
    std::cin >> x >> a;

    std::cout << x << "^" << a << " = " << pow(x, a) << '\n';

    return 0;
}

int pow(const int &x, const int &n) { 
    if (n == 0) return 1;
    else return x * pow(x, n-1);
}
