#include <iostream>

int main() {
    int vec[3] = {42, 43, 44};

    // Counting for loop.
    for (int i = 0; i < 3; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Range-based for loop.
    for (auto const i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}