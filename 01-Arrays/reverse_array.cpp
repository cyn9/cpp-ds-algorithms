#include <iostream>
#include <algorithm>

void print(const int [], std::size_t);
void reverseArray(int [], std::size_t);

int main() {
    std::size_t N {0};

    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    int arr[N];
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << "Enter the element " << (i+1) << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Array elements before reverse:\n";
    print(arr, N);

    // Reverse the array:
    reverseArray(arr, N);

    std::cout << "Array elements after reverse:\n";
    print(arr, N);

    return 0;
}

void reverseArray(int arr[], std::size_t N) {
    int start = 0;
    int end = N-1;

    while (start < end) {
        std::swap(arr[start], arr[end]);

        start++;
        end--;
    }
}

void print(const int arr[], std::size_t N) {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
}
