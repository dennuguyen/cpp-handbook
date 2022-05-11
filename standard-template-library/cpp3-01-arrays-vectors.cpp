#include <array>
#include <iostream>
#include <vector>

auto main() -> int {

    // Different ways to initialise a vector.
    auto vec1 = std::vector<int>({1, 2, 3, 4, 5, 6});            // Initialiser list.
    auto vec2 = std::vector<int>(vec1);                          // Using another vector.
    auto vec3 = std::vector<int>(vec1.begin(), vec2.end() - 3);  // Using iterators.

    // When to use a vector vs array?
    auto arr1 = std::array<int, 10>({3, 1, 0, 2, 3});  // Array with at most 10 elements.

    // What's the difference between [] and at()?
    arr1[0] = 3;     // Can access arrays/vectors with [] operator.
    arr1.at(0) = 5;  // Can access arrays/vectors with .at().

    // What else can we do?
    if (!arr1.empty()) {
        arr1.resize(5);
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] == arr1.front()) {
                std::cout << arr1[i] << std::endl;
            }
        }
    }

    return 0;
}