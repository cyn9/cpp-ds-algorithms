#include <iostream>

template <std::size_t rows, std::size_t cols>
void printMatrix(const int (&arr)[rows][cols]);

int main() {
    // A 2-by-3 matrix:
    int m1[2][3] = { {1, 2, 3},
                     {4, 5, 6} };

    // A 3-by-4 matrix (all zeros):
    int m2[3][4] = { {0} };

    // A 5-by-4 matrix (partially filled):
    int m3[5][4] = { { 1, 2}, 
                     { 3 },
                     { 4, 5, 6} };

    std::cout << "Matrix 1: " << '\n';
    printMatrix(m1);

    std::cout << "\nMatrix 2: " << '\n';
    printMatrix(m2);

    std::cout << "\nMatrix 3: " << '\n';
    printMatrix(m3);

    return 0;
}

// Pass by reference without losing size information:
template <std::size_t rows, std::size_t cols>
void printMatrix(const int (&arr)[rows][cols]) {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j)
            std::cout << arr[i][j] << "  ";
        
        std::cout << '\n';
    }
}