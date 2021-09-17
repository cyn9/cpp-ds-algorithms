#include <iostream>
#include <string>
#include <stack>

std::string remove_duplicates(const std::string &);

int main() {
    const std::string string1 = "Mississippi";
    const std::string string2 = "abbaca";
    const std::string string3 = "aaabccddd";

    std::string result1 = remove_duplicates(string1);
    std::string result2 = remove_duplicates(string2);
    std::string result3 = remove_duplicates(string3);

    std::cout << result1 << '\n';
    std::cout << result2 << '\n';
    std::cout << result3 << '\n';

    return 0;
}

// T = O(n), S = O(n)
std::string remove_duplicates(const std::string &str) {
    std::stack<char> char_stack;

    if (char_stack.empty()) { char_stack.push(str.at(0)); }
    
    for (std::size_t i = 1; i < str.length(); ++i) {
        if (!char_stack.empty()) {
            if (str.at(i) != char_stack.top()) {
                char_stack.push(str.at(i));
            }
            else {
                char_stack.pop();
            }
        }
        else {
            char_stack.push(str.at(i));
        }
    }

    std::size_t len = char_stack.size();
    std::string result(len, ' ');

    for (std::size_t i = 0; i < len; ++i) {
        result.at(len-i-1) = char_stack.top();
        char_stack.pop();
    }
    
    return result;
}
