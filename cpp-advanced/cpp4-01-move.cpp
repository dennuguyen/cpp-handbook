#include <iostream>
#include <vector>

int main() {
    std::cout << std::boolalpha;
    {  // Moving
        auto v1 = std::vector<int>({1, 2, 3});
        auto v2 = std::move(v1);  // v1 turned into an Rvalue which can be assigned to an Lvalue.
        std::cout << v1.empty() << std::endl;
        std::cout << v2.empty() << std::endl;
    }
    {  // Copying
        auto v1 = std::vector<int>({1, 2, 3});
        auto v2 = v1;
        std::cout << v1.empty() << std::endl;
        std::cout << v2.empty() << std::endl;
    }

    return 0;
}