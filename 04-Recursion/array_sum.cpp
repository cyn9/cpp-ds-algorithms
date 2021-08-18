#include <iostream>

int sum(const int [], std::size_t);

int main() {
    constexpr int test1[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    constexpr int test2[] {2, 4, 6, 8, 10};

    constexpr std::size_t n1 { sizeof(test1) / sizeof(test1[0]) };
    constexpr std::size_t n2 { sizeof(test2) / sizeof(test2[0]) };

    std::cout << "Sum of test1 = " << sum(test1, n1) << '\n';
    std::cout << "Sum of test2 = " << sum(test2, n2) << '\n';

    return 0;
}

int sum(const int arr[], std::size_t N) {
    // Base case:
    if (N == 0) { return 0; }

    return (*arr) + sum(arr+1, N-1);
}