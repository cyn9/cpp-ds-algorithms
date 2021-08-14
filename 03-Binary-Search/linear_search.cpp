#include <iostream>

int linearSearch(const int [], const std::size_t &, const int &);

int main() {
    int value {0};
    std::size_t N {0};

    std::cout << "Enter number of elements >> ";
    std::cin >> N;

    int arr[N];

    std::cout << "Enter the array elements >> ";
    for (auto i = 0; i < N; ++i)
        std::cin >> arr[i];
    
    std::cout << "Enter an item to be searched >> ";
    std::cin >> value;

    // Return the position of the value in the array:
    // Return -1 if not found.
    int pos = linearSearch(arr, N, value);

    // Invalid index check (-1)
    if (pos != -1)
        std::cout << "Found " << value << " at index " << pos << '\n';
    else
        std::cout << "Not found.\n";

    return 0;
}

int linearSearch(const int a[], const std::size_t &size, const int &value) {
    for (auto i = 0; i < size; ++i)
        if (a[i] == value)
            return i;
    
    return -1;
}
