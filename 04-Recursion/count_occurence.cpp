#include <iostream>

void findCount(const int [], const std::size_t &, int &, int &);
int findCount(const int [], const std::size_t &, int &);

int main() {
    // Test array:
    constexpr int arr[] = {5, 5, 6, 5, 5, 6, 5, 7, 5, 6, 5};
    constexpr std::size_t N = sizeof(arr) / sizeof(arr[0]);

    int c {0};
    int value {0};

    std::cout << "Enter a number >> ";
    std::cin >> value;

    // Test approach 1:
    findCount(arr, N, value, c);

    std::cout << "First approach: ";
    if (c == 0) 
        std::cout << value << " does not exist in the array.\n";
    else
        std::cout << value << " occurs " << c << " times." << '\n';
    
    // Test approach 2:
    int c2 = findCount(arr, N, value);

    std::cout << "Second approach: ";
    if (c2 == 0) 
        std::cout << value << " does not exist in the array.\n";
    else
        std::cout << value << " occurs " << c2 << " times." << '\n';
    
    return 0;
}

// First approach is to store the number of times "value" occurs with a variable
// "count":
void findCount(const int arr[], const std::size_t &N, int &value, int &count) {
    if (N == 0) { return; }
    if (*arr == value) { count++; }

    findCount(arr+1, N-1, value, count);
}

// Second approach is to return the number of times "value" occurs inside the
// array directly:
int findCount(const int arr[], const std::size_t &N, int &value) { 
    // Check if the smaller problem is a finite-sized array:
    if (N > 0) {
        if (*arr == value) return 1 + findCount(arr+1, N-1, value);
        else               return     findCount(arr+1, N-1, value);
    }

    // Return zero if the smaller problem goes out of the array bounds:
    return 0;
}
