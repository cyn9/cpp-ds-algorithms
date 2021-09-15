#include <iostream>
#include <vector>
#include <string>
#include <stack>

int evaluateRPN(const std::vector<std::string> &);

int main() {
    std::vector<std::string> tok1 = {"4", "13", "5", "/", "+"};
    std::cout << "Result = " << evaluateRPN(tok1) << '\n';

    std::vector<std::string> tok2 = {"10", "6", "9", 
                                     "3", "+", "-11", 
                                     "*", "/", "*",
                                     "17", "+", "5", "+"};
    std::cout << "Result = " << evaluateRPN(tok2) << '\n';

    std::vector<std::string> tok3 = {"2", "1", "+", "3", "*"};
    std::cout << "Result = " << evaluateRPN(tok3) << '\n';

    return 0;
}

int evaluateRPN(const std::vector<std::string> &tokens) {
    std::stack<int> operands;

    for (std::size_t i = 0; i < tokens.size(); ++i) {
        if (tokens.at(i) == "+" || 
            tokens.at(i) == "-" || 
            tokens.at(i) == "*" || 
            tokens.at(i) == "/") 
        {
            int temp1 = operands.top();
            operands.pop();

            int temp2 = operands.top();
            operands.pop();

            if (tokens.at(i) == "+")
                operands.push(temp2 + temp1);
            else if (tokens.at(i) == "-")
                operands.push(temp2 - temp1);
            else if (tokens.at(i) == "*")
                operands.push(temp2 * temp1);
            else if (tokens.at(i) == "/")
                operands.push(temp2 / temp1);
        }
        else {
            operands.push(std::stoi(tokens.at(i)));
        }
    }

    return operands.top();
}