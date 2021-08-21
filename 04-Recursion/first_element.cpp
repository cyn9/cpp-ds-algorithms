#include <iostream>

int firstElement(const int [], const std::size_t &, const int &, std::size_t);

int main() {
    constexpr int test1[] {5, 5, 5, 6, 5, 6};
    constexpr int test2[] {1, 2, 3, 3, 3, 4, 4, 7};

    constexpr std::size_t N1 { sizeof(test1) / sizeof(test1[0]) };
    constexpr std::size_t N2 { sizeof(test2) / sizeof(test2[0]) };

    int idx1 {0};
    int idx2 {0};
    int idx3 {0};
    idx1 = firstElement(test1, N1, 6, idx1);
    idx2 = firstElement(test2, N2, 4, idx2);
    idx3 = firstElement(test2, N2, 123, idx3); // Not exists

    if (idx1 != -1)
        std::cout << "Found at index = " << idx1 << '\n';
    
    if (idx2 != -1)
        std::cout << "Found at index = " << idx2 << '\n';
    
    if (idx3 != -1)
        std::cout << "Found at index = " << idx3 << '\n';
    else
        std::cout << "Cannot find the element." << '\n';

    return 0;
}

int firstElement(const int arr[], const std::size_t &N, const int &x, std::size_t index) {
    if (index == N)      { return -1; }
    if (arr[index] == x) { return index; }

    return firstElement(arr, N, x, index + 1);
}
