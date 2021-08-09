#include <iostream>

void printReverse(const int [], std::size_t);

int main() {
    std::size_t N {0};

    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    int arr[N];
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << "Enter the element " << (i+1) << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Array elements in reverse order:\n";
    printReverse(arr, N);
    
    return 0;
}

void printReverse(const int arr[], std::size_t N) {
    for (std::size_t i = 1; i <= N; ++i)
        std::cout << arr[N-i] << " ";

    std::cout << '\n';
}
