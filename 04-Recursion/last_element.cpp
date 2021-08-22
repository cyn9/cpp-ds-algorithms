#include <iostream>
#include <cassert>

int lastElement(const int [], const std::size_t &, const int &);

int main() {
    constexpr int test1[] {5, 5, 5, 6, 5, 6};
    constexpr int test2[] {1, 2, 3, 3, 3, 4, 4, 7};

    constexpr std::size_t N1 { sizeof(test1) / sizeof(test1[0]) };
    constexpr std::size_t N2 { sizeof(test2) / sizeof(test2[0]) };

    int idx1 {0};
    int idx2 {0};
    int idx3 {0};
    idx1 = lastElement(test1, N1, 5);
    idx2 = lastElement(test2, N2, 1);
    idx3 = lastElement(test2, N2, 999); // Does not exists

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

int lastElement(const int arr[], const std::size_t &N, const int &x) {
    if (N == 0)        { return  -1; }
    if (arr[N-1] == x) { return N-1; }

    return lastElement(arr, N-1, x);
}
