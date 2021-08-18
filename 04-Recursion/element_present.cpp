#include <iostream>

bool is_present(const int [], const std::size_t, const int &);
void print(const int [], const std::size_t &);

int main() {
    constexpr int test[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    constexpr int value1 {4};
    constexpr int value2 {13};

    constexpr std::size_t n { sizeof(test) / sizeof(test[0]) };
    print(test, n);

    std::cout << std::boolalpha;
    std::cout << "Number " << value1 << " is present? " << is_present(test, n, value1) << '\n';
    std::cout << "Number " << value2 << " is present? " << is_present(test, n, value2) << '\n';

    return 0;
}

bool is_present(const int arr[], const std::size_t N, const int &value) {
    // Check if the array's i-th element is present:
    if (*arr == value) { return true; }

    // Base case at which the recursion stops.
    // All elements are checked but value is not found:
    if (N == 0) { return false; }

    return is_present(arr+1, N-1, value);
}

void print(const int arr[], const std::size_t &N) {
    std::cout << "Test array >> ";
    for (std::size_t i = 0; i < N; ++i)
        std::cout << arr[i] << ' ';
    
    std::cout << '\n';
}
