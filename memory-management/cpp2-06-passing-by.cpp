#include <iostream>
#include <memory>

// Pass by value.
auto byValue(int a) -> void { a = 2; }

// Pass by reference.
auto byReference(int& a) -> void { a = 3; }

// Pass by pointer.
auto byPointer(std::shared_ptr<int> a) -> void { *a = 4; }

auto main() -> int {
    {
        int a = 1;
        byValue(a);
        std::cout << a << std::endl;
    }

    {
        int var = 1;
        auto& a = var;
        byReference(a);
        std::cout << a << std::endl;
    }

    {
        auto a = std::make_shared<int>(1);
        byPointer(a);
        std::cout << *a << std::endl;
    }

    return 0;
}