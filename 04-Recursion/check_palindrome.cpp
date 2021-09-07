#include <iostream>

bool isPalindrome(const int [], const std::size_t &);

int main() {
    int test1[] {1, 3, 3, 1};
    int test2[] {1, 4, 3, 2};
    int test3[] {1, 3, 2, 5, 5, 2, 3, 1};

    const auto N1 { sizeof(test1) / sizeof(test1[0]) };
    const auto N2 { sizeof(test2) / sizeof(test2[0]) };
    const auto N3 { sizeof(test3) / sizeof(test3[0]) };

    std::cout << std::boolalpha;
    std::cout << isPalindrome(test1, N1) << '\n';
    std::cout << isPalindrome(test2, N2) << '\n';
    std::cout << isPalindrome(test3, N3) << '\n';
    
    return 0;
}

bool isPalindrome(const int arr[], const std::size_t &N) {
    // Base case:
    if (N < 2) {
        return true;
    }

    if (*arr == *(arr+N-1)) {
        // Create a temporary array for smaller problem:
        int temp[N-2];

        // Fill up the smaller problem array omitting start
        // and end values in the array passed to the function.
        for (int i = 0; i < N-2; ++i) {
            temp[i] = *(arr+i+1);
        }

        return isPalindrome(temp, N-2); 
    }
    else {
        return false; 
    }
}
