#include <iostream>

std::size_t getLength(const char [], std::size_t);

int main() {
    constexpr std::size_t size {100};
    char test[size];

    std::cout << "Enter a test string: ";
    std::cin.getline(test, size);

    std::cout << test << '\n';

    std::cout << "Length of the test string: " << getLength(test, size) << '\n';

    return 0;
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
