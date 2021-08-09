#include <iostream>
#include <algorithm>

void reverseString(char [], std::size_t);
std::size_t getLength(const char [], std::size_t);

int main() {
    constexpr std::size_t size {100};
    char test[size];

    std::cout << "Enter a test string: ";
    std::cin.getline(test, size);

    std::cout << "Test string before reverse: ";
    std::cout << test << '\n';

    reverseString(test, size);

    std::cout << "Test string after reverse: ";
    std::cout << test << '\n';

    return 0;
}

void reverseString(char str[], std::size_t size) {
    int first {0};
    int last  {static_cast<int> (getLength(str, size)) - 1};

    while (first < last) {
        std::swap(str[first], str[last]);

        first++;
        last--;
    }
}

std::size_t getLength(const char arr[], std::size_t size) {
    std::size_t count {0};

    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] != '\0')
            count++;
        else
            break;
    }

    return count;
}
