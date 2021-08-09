#include <iostream>

int main() {
    std::size_t N {0};
    int sum {0};

    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    int arr[N];
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << "Enter the element " << (i+1) << ": ";
        std::cin >> arr[i];
    }

    for (std::size_t i = 0; i < N; ++i)
        sum += arr[i];

    std::cout << "Sum: " << sum << '\n';

    return 0;
}
