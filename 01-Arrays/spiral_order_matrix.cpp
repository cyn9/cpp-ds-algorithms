#include <iostream>
#include <vector>

// Spiral order matrix:
// Space complexity: S = O(1)
// Time complexity: T = O(mn); m = # of rows, n = # of columns

std::vector<int> spiralOrder(std::vector< std::vector<int> > &);
void print(const std::vector<int> &);

int main() {
    std::vector<std::vector<int>> test1 { {1, 2, 3},
                                          {4, 5, 6},
                                          {7, 8, 9} };

    std::vector<std::vector<int>> test2 { {1,  2,  3,  4,  5,  6},
                                          {7,  8,  9,  10, 11, 12},
                                          {13, 14, 15, 16, 17, 18} };

    std::vector<int> spiral_order_test1 = spiralOrder(test1);
    std::vector<int> spiral_order_test2 = spiralOrder(test2);
    print(spiral_order_test1);
    print(spiral_order_test2);
    
    return 0;
}

std::vector<int> spiralOrder(std::vector< std::vector<int> >& matrix) {
    std::size_t m {matrix.size()};
    std::size_t n {matrix[0].size()};

    int start_row {0};
    int start_col {0};
    int end_row {static_cast<int>(m) - 1};
    int end_col {static_cast<int>(n) - 1};

    std::vector<int> result;
    if (m == 0 || n == 0) return result;

    result.reserve(m*n);

    while (start_row <= end_row && start_col <= end_col) {
        // Print the start_row elements:
        for (auto i = start_col; i <= end_col; ++i) {
            result.push_back(matrix[start_row][i]);
        }
        start_row++;
        if (result.size() == m*n) { break; }

        // Print the end_col elements:
        for (auto i = start_row; i <= end_row; ++i) {
            result.push_back(matrix[i][end_col]);
        }
        end_col--;
        if (result.size() == m*n) { break; }

        // Print the end_row elements:
        for (auto i = end_col; i >= start_col; i--) {
            result.push_back(matrix[end_row][i]);
        }
        end_row--;
        if (result.size() == m*n) { break; }

        // Print start_col elements:
        for (auto i = end_row; i >= start_row; i--) {
            result.push_back(matrix[i][start_col]);
        }
        start_col++;
        if (result.size() == m*n) { break; }
    }

    return result;
}

void print(const std::vector<int> &vec) {
    std::cout << "[ ";

    for (const auto &e: vec)
        std::cout << e << " ";

    std::cout << "]\n";
}