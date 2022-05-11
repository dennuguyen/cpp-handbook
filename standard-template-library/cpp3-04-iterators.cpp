#include <iostream>
#include <vector>

auto main() -> int {

    auto vec = std::vector<int>({1, 2, 3, 4, 5, 6});

    {  // Avoid this if you can.
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    {  // Better using iterators.
        for (auto it = vec.begin(); it < vec.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {  // Can do some iterator arithmetic.
        std::cout << *(vec.begin() + 3) << std::endl;
        std::cout << *vec.end() << std::endl;  // Prints garbage.
    }

    return 0;
}