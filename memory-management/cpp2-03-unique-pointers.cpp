#include <iostream>
#include <memory>

auto main() -> int {
    auto uniquePtr = std::make_unique<int>(42);

    // Can dereference a smart pointer.
    {
        std::cout << *uniquePtr << std::endl;  // Same as raw pointer.
    }

    // How to get the pointer's value aka the address the pointer is
    // pointing at?
    {
        std::cout << uniquePtr << std::endl;
        std::cout << uniquePtr.get() << std::endl;
    }

    return 0;
}