#include <iostream>

bool stringCompare(const char [], const char []);
std::size_t getLength(const char []);

int main() {
    std::cout << std::boolalpha;

    constexpr std::size_t size {100};

    char str1[size];
    char str2[size];

    std::cout << "Enter string 1: ";
    std::cin.getline(str1, size);

    std::cout << "Enter string 2: ";
    std::cin.getline(str2, size);

    std::cout << "Length of string 1: " << getLength(str1) << '\n';
    std::cout << "Length of string 2: " << getLength(str2) << '\n';

    bool result = stringCompare(str1, str2);
    std::cout << "Result: " << result << '\n';

    return 0;
}

bool stringCompare(const char arr1[], const char arr2[]) {
    if (getLength(arr1) != getLength(arr2)) {
        return false;
    }
    else {
        // Compare each character in the arrays:
        for (int i = 0; arr1[i] != '\0'; ++i) {
            if (arr1[i] - arr2[i] != 0) {
                return false;
            }
        }
    }

    return true;
}

std::size_t getLength(const char arr[]) {
    std::size_t count {0};

    for (int i = 0; arr[i] != '\0'; ++i)
        count++;

    return count;
}