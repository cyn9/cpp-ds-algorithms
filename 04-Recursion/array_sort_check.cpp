#include <iostream>

bool is_sorted(const int [], const std::size_t);

int main() {
    constexpr std::size_t N {10};

    constexpr int test1[N] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    constexpr int test2[N] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << std::boolalpha;
    std::cout << "Test 1 is sorted? " << is_sorted(test1, N) << '\n';
    std::cout << "Test 2 is sorted? " << is_sorted(test2, N) << '\n';

    return 0;
}

bool is_sorted(const int arr[], const std::size_t N) {
    // Base case:
    if (N == 0 || N == 1) { return true; }

    if (*arr > *(arr+1))  { return false; }
    else                  { return is_sorted(arr+1, N-1); }
}
