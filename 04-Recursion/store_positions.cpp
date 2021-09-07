#include <iostream>
#include <vector>

void storePositions(const int [], std::vector<int> &, const int, int, const std::size_t &);
void printVector(const std::vector<int> &);
void printArray(const int [], const std::size_t &);

int main() {
    constexpr int test_array[] {5, 5, 6, 7, 8, 6, 5, 6, 5};
    constexpr std::size_t N {sizeof(test_array) / sizeof(test_array[0])};
    constexpr int i {0};

    int value {0};
    std::cout << "Enter a number >> ";
    std::cin >> value;

    std::vector<int> positions {};
    storePositions(test_array, positions, i, value, N);

    printArray(test_array, N);
    printVector(positions);

    return 0;
}

void storePositions(const int arr[], std::vector<int>& pos, const int index, int value, const std::size_t& N) {
    if (index == N) { return; }

    if (arr[index] == value) { pos.push_back(index); }

    storePositions(arr, pos, index+1, value, N);
}

void printVector(const std::vector<int>& V) {
    std::cout << "Position vector content >> ";
    for (const auto &e: V)
        std::cout << e << ' ';
    
    std::cout << '\n';
}

void printArray(const int arr[], const std::size_t &N) {
    std::cout << "Array content >> ";
    for (auto i = 0; i < N; ++i)
        std::cout << arr[i] << ' ';
    
    std::cout << '\n';
}
