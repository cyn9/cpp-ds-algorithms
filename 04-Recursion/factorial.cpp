#include <iostream>
#include <exception>
#include <memory>

int fact(const int &);

class InvalidArgument : std::exception {
    public:
		virtual const char* what() const noexcept {
			return "ERROR: Argument cannot be negative...";
        }
};

int main() {
    int number {0};

    std::cout << "Enter a number >> ";
    std::cin >> number;

    auto result = std::make_unique<int> (fact(number));
    if (number >= 0) {
        std::cout << number << "! = " << *result << '\n';
    }

    return 0;
}

int fact(const int &n) {
    try {
        if (n < 0)                 { throw InvalidArgument(); }
        else if (n == 0 || n == 1) { return 1; }
        else                       { return n * fact(n - 1); }
    }
    catch(const InvalidArgument &e) {
        std::cout << e.what() << '\n';
        return 0;
    }
}
