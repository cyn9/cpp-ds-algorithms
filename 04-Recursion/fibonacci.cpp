#include <iostream>
#include <exception>

int fib(const int &);

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

    int result = fib(number);
    if (number > 0)
        std::cout << "Fib(" << number << ") = " << result << '\n';

    return 0;
}

int fib(const int &n) { 
    try {
        if (n < 0)  { throw InvalidArgument(); }
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
    }
    catch(const InvalidArgument &e) {
        std::cout << e.what() << '\n';
        return 0;
    }
    
    return fib(n-1) + fib(n-2);
}
