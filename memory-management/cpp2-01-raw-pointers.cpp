#include <iostream>

auto main() -> int {
    int val = 3;
    int* ptr = &val;   // ptr points to address-of val.
    int deref = *ptr;  // assign deref the derefence of ptr.

    {
        std::cout << val << std::endl;
        std::cout << &val << std::endl;
    }

    {
        std::cout << ptr << std::endl;
        std::cout << *ptr << std::endl;
        std::cout << deref << std::endl;
    }

    {
        *ptr = 1;
        std::cout << val << std::endl;  // What will this print out?
    }
}