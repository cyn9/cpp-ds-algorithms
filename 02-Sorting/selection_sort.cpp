#include <iostream>
#include <climits>

void selectionSort(int [], std::size_t);
void print(const int [], std::size_t);

int main() {
    constexpr std::size_t len {5};
    std::size_t N {0};

    int a[] {7, 5, 3, 6, 8};
    int b[] {4, 5, 3, 1, 2};

    std::cout << "Enter the length of the array >> ";
    std::cin >> N;

    int c[N];
    std::cout << "Enter the array elements >> ";
    for (auto i = 0; i < N; ++i)
        std::cin >> c[i];
 
    std::cout << "Test 1:\n";
    std::cout << "Before sorting: ";
    print(a, len);
    selectionSort(a, len);

    std::cout << "After sorting: ";
    print(a, len);

    std::cout << "\nTest 2:\n";
    std::cout << "Before sorting: ";
    print(b, len);
    selectionSort(b, len);

    std::cout << "After sorting: ";
    print(b, len);

    std::cout << "\nTest 3:\n";
    std::cout << "Before sorting: ";
    print(c, N);
    selectionSort(c, N);

    std::cout << "After sorting: ";
    print(c, N);

    return 0;
}

void selectionSort(int arr[], std::size_t N) {
    // Traverse the array with a position variable i:
    for (auto i = 0; i < N-1; ++i) {
        int min {INT_MAX};
        std::size_t minIndex {};

        // Find the minimum of the right-hand side:
        for (auto j = i+1; j < N; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }

        // Swap if ith element is greater than the minimum:
        if (min < arr[i])
            std::swap(arr[i], arr[minIndex]);
    }
}

void print(const int arr[], std::size_t N) {
    std::cout << "[ ";
    for (auto i = 0; i < N; ++i) 
        std::cout << arr[i] << " ";
    
    std::cout << "]\n";
}
