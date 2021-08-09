#include <iostream>
#include <climits>

int main() {
    std::size_t N   {0};
    int largest     {INT_MIN};
    int smallest    {INT_MAX};
    
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    int arr[N];
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << "Enter the element " << (i+1) << ": ";
        std::cin >> arr[i];
    }

    for (std::size_t i = 0; i < N; ++i) {
        if (arr[i] > largest) 
            largest = arr[i];

        if (arr[i] < smallest) 
            smallest = arr[i];
    }

    std::cout << "The largest element is " << largest << '\n';
    std::cout << "The smallest element is " << smallest << '\n';

    return 0;
}
