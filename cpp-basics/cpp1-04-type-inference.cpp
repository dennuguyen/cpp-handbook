#include <array>
#include <iostream>
#include <vector>

int main() {
    {
        std::array<std::array<int, 4>, 4> matrix;
        std::array<int, 4> firstRow = matrix[0];
        for (std::array<int, 4> row : matrix) {
        }
    }
    {
        auto matrix = std::array<std::array<int, 4>, 4>();
        auto firstRow = matrix[0];
        for (auto row : matrix) {
        }
    }
    {
        double val1 = 3.3;
        int val2 = val1;
    }
    {
        auto val1 = 3.3;
        auto val2 = static_cast<int>(val1);  // Enforce explicit conversion.
    }
}