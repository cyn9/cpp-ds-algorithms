#include <iostream>

void bubbleSort(int [], std::size_t);
void print(const int [], std::size_t);

int main() {
    constexpr std::size_t len {5};

    int a[] {7, 5, 3, 6, 8};
    int b[] {1, 2, 3, 4, 5};        // Already sorted (best case)
    int c[] {50, 40, 30, 20, 10};   // Sorted descending order (worst case)
    
    std::cout << "Test 1:\n";
    std::cout << "Before sorting: ";
    print(a, len);
    bubbleSort(a, len);

    std::cout << "After sorting: ";
    print(a, len);

    std::cout << "\nTest 2:\n";
    std::cout << "Before sorting: ";
    print(b, len);
    bubbleSort(b, len);

    std::cout << "After sorting: ";
    print(b, len);

    std::cout << "\nTest 3:\n";
    std::cout << "Before sorting: ";
    print(c, len);
    bubbleSort(c, len);

    std::cout << "After sorting: ";
    print(c, len);
}

void bubbleSort(int arr[], std::size_t N) {
    int numOfIterations {0};
    bool is_sorted {true};

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N-1; ++j) {
            if (arr[j+1] < arr[j]) {
                std::swap(arr[j+1], arr[j]);
                numOfIterations++;
                is_sorted = false;
            }
        }

        // Run the inner for loop (N-1) times. is_sorted holds the
        // information whether the array is sorted or not. If it's 
        // already sorted, the outer loop will only run once. Hence,
        // it is of O(n).
        if (is_sorted) {
            std::cout << "The array is already sorted.\n";
            break;
        }
    }

    std::cout << "Number of iterations: " << numOfIterations << '\n';
}

void print(const int arr[], std::size_t N) {
    std::cout << "[ ";
    for (std::size_t i = 0; i < N; ++i) 
        std::cout << arr[i] << " ";
    
    std::cout << "]\n";
}
