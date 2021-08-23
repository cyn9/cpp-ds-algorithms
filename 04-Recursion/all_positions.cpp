#include <iostream>

void print(const int [], const std::size_t &);
void getIndex(const int [], const std::size_t &, int &, int);

int main() {
    int value {0};
    
    std::size_t size {0};

    std::cout << "Enter the number of elements >> ";
    std::cin >> size;

    int arr[size];

    for (auto i = 0; i < size; ++i) {
        std::cout << "Enter element " << (i+1) << " >> ";
        std::cin >> arr[i];
    }

    print(arr, size);

    std::cout << "Enter a value >> ";
    std::cin >> value;

    getIndex(arr, size, value, 0);

    return 0;
}

void print(const int arr[], const std::size_t &size) {
    std::cout << "Array elements >> ";

    for (auto i = 0; i < size; ++i)
        std::cout << arr[i] << " ";

    std::cout << '\n';
}

void getIndex(const int arr[], const std::size_t &N, int &value, int index) {
    if (N == index) { std::cout << '\n'; return; }

    if (arr[index] == value)
        std::cout << index << " ";

    return getIndex(arr, N, value, index+1);
}
