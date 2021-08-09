#include <iostream>
#include <cstring>

void concat(char [], const char []);

int main() {
    constexpr std::size_t size {100};
    char str1[size];
    char str2[size];

    std::cout << "Enter string 1: ";
    std::cin.getline(str1, size);

    std::cout << "Enter string 2: ";
    std::cin.getline(str2, size);

    std::cout << "String 1: ";
    std::cout << str1 << '\n';;
    std::cout << "String 2: ";
    std::cout << str2 << '\n';

    concat(str1, str2);
    std::cout << "End result: ";
    std::cout << str1 << '\n';

    return 0;
}

void concat(char dest[], const char src[]) {
    std::size_t size_dest {strlen(dest)};

    for (int i = 0; src[i] != '\0'; ++i)
        dest[i + size_dest] = src[i];
}
