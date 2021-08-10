#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Testing some string operations:
    std::string a {"abc"};
    std::string b {"def"};
    std::string c {a + b};

    std::string d {"xyz"};
    d += a + b + c;

    // Substring and find functions:
    std::cout << d.substr(3, 6) << std::endl;

    std::string e {d.substr(3, 6)};

    std::cout << e << '\n';

    std::string s1 {"xyzabcabcabc"};
    std::size_t pos = s1.find("abc");
    std::string s2 = s1.substr(pos);
    std::string s3 = s1.substr(pos, 4);

    std::cout << "abc position: " << pos << '\n';
    std::cout << s1 << '\n';
    std::cout << s2 << '\n';
    std::cout << s3 << '\n';

    // Integer to string:
    int number {1234};
    std::string s4 = std::to_string(number);
    std::cout << s4 << '\n';

    // String to integer:
    std::string s5 {"192837"};
    int value = std::stoi(s5);
    std::cout << value << '\n';

    return 0;
}
