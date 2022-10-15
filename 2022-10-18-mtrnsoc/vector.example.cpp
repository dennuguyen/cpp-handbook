#include <iostream>
#include <vector>

int main() {
    // Helper function to print vector.
    auto print = [](std::vector<int> v) {
        for (auto const& i : v) std::cout << i << " ";
        std::cout << std::endl;
    };

    // Creating a vector with size.
    {
        std::vector<int> v1;  // Default constructor -> size of 0.
        std::cout << v1.size() << std::endl;

        std::vector<int> v2(3);  // Size of 3.
        std::cout << v2.size() << std::endl;

        std::vector<int> v3(4);  // Size of 4.
        std::cout << v3.size() << std::endl;
    }

    // Segmentation fault example.
    {
        // Bad.
        std::vector<int> v4;
        v4[0];  // Seg fault.

        // Good.
        std::vector<int> v5;
        v5.resize(1);
        v5[0];  // No seg fault.
    }

    // Creating a vector with initialiser list.
    {
        std::vector<int> v6{0};  // [0].
        std::cout << v6.size() << std::endl;
        print(v6);

        std::vector<int> v7{1, 2, 3};  // [1, 2, 3].
        std::cout << v7.size() << std::endl;
        print(v7);
    }
}