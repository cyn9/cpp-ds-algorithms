#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string &);

int main() {
    std::string test1 = "()";
    std::string test2 = "()]]{]";
    std::string test3 = "(){}[]";

    std::cout << std::boolalpha;
    std::cout << "Test 1 is valid? " << isValid(test1) << '\n';
    std::cout << "Test 2 is valid? " << isValid(test2) << '\n';
    std::cout << "Test 3 is valid? " << isValid(test3) << '\n';

    return 0;
}

// Parantheses are: '{', '}', '[', ']', '{' and '}'.
// T = O(n)
bool isValid(const std::string &str) {
    std::stack<char> char_stack;

    for (std::size_t i = 0; i < str.length(); ++i) {
        // Directly push whatever the opening bracket there exists.
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            char_stack.push(str[i]);
        }
        else {
            // Return false if the stack is empty. This means the input string
            // only has closing brackets.
            if (char_stack.empty()) { return false; }
            else if (str[i] == ')') {
                if (char_stack.top() == '(') { char_stack.pop(); }
                else { return false; }
            }
            else if (str[i] == ']') {
                if (char_stack.top() == '[') { char_stack.pop(); }
                else { return false; }
            }
            else if (str[i] == '}') {
                if (char_stack.top() == '{') { char_stack.pop(); }
                else { return false; }
            }
        }
    }

    if (char_stack.empty()) { return true; }

    return false;
}
